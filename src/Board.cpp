/*
** ARTHUR MASSANES PROJECT, 2020
** gameoflife
** File description:
** board class
*/

#include "Board.hpp"

Board::Board(void)
{
    for (int y = 0; y < BOARD_SIZE; y++) {
        _map.push_back("");
        for (int x = 0; x < BOARD_SIZE; x++)
            _map[y] += " ";
    }
    _rect.setFillColor(_cellColor);
    _rect.setSize(sf::Vector2f(_cellSize, _cellSize));
}

void Board::dump(void)
{
    for (const std::string &line: _map) {
        std::cout << line << "\n";
    }
}

bool Board::loadFromFile(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;
    unsigned int y = 0;
    unsigned int x = 0;

    if (!file) {
        std::cerr << "Could not read file '" << fileName << "'\n";
        return (false);
    }
    while (std::getline(file, line)) {
        x = 0;
        for (const char &c: line) {
            if (x >= _map[y].length())
                _map[y] += c;
            else
                _map[y][x] = c;
            x++;
        }
        y++;
        if (y >= _map.size())
            _map.push_back(std::string());
    }
    return (true);
}

int Board::getHeight(void) const
{
    return (_map.size());
}

int Board::getWidth(int y) const
{
    if (y < 0 || (unsigned)y > _map.size())
        throw Error("Column out of range", "Board::getWidth");
    return (_map[y].length());
}

bool Board::isInvalidPos(sf::Vector2f pos) const noexcept
{
    if (pos.x < 0 || pos.y < 0)
        return (true);
    else if (pos.y >= getHeight() || pos.x >= getWidth(pos.y))
        return (true);
    else
        return (false);
}

bool Board::isCellAlive(sf::Vector2f pos) const
{
    if (isInvalidPos(pos)) {
        return (false);
    }
    return (_map[pos.y][pos.x] != DEAD_CELL);
}

void Board::animateColor(void)
{
    int off = _reverseColor ? -5 : 5;

    if (_cellColor.r >= 250)
        _reverseColor = true;
    else if (_cellColor.r <= 100)
        _reverseColor = false;
    _cellColor.r += off;
    _rect.setFillColor(_cellColor);
}

void Board::draw(sf::RenderWindow *window)
{
    sf::Vector2f pos = { .x = (float)0, .y = (float)0};
    sf::RectangleShape _grid;

    _grid.setSize(sf::Vector2f(2, 2));
    _grid.setFillColor(sf::Color::Black);
    this->animateColor();
    for (const std::string &row: _map) {
         pos.x = 0 + _offset;
        for (const char &c: row) {
            if (c != DEAD_CELL) {
                _rect.setPosition(pos);
                window->draw(_rect);
            }
            pos.x += _cellSize;
            _grid.setPosition(pos);
            if (_isGridVisible)
                window->draw(_grid);
        }
        pos.y += _cellSize;
    }
}

void Board::setGridVisibility(bool visible)
{
    _isGridVisible = visible;
}

bool Board::isGridVisible(void) const
{
    return (_isGridVisible);
}

void Board::toggleGridVisibility(void)
{
    _isGridVisible = !_isGridVisible;
}

unsigned int Board::getNbNeighbors(sf::Vector2f pos) const
{
    unsigned int nb = 0;
    std::vector<sf::Vector2f> neighbors = {
        // top row
        { .x = pos.x - 1, .y = pos.y - 1 },
        { .x = pos.x, .y = pos.y - 1 },
        { .x = pos.x + 1, .y = pos.y - 1 },

        // cell row
        { .x = pos.x - 1, .y = pos.y },
        { .x = pos.x + 1, .y = pos.y },

        // bottom row
        { .x = pos.x - 1, .y = pos.y + 1 },
        { .x = pos.x, .y = pos.y + 1 },
        { .x = pos.x + 1, .y = pos.y + 1 },
    };

    for (const sf::Vector2f &pos: neighbors)
        nb = isCellAlive(pos) ? nb + 1 : nb;
    return (nb);
}

bool Board::shouldCreateCell(sf::Vector2f pos) const noexcept
{
    int neighbors = 0;

    if (isCellAlive(pos))
        return (false);
    neighbors = getNbNeighbors(pos);
    if (neighbors == 3)
        return (true);
    return (false);
}

bool Board::shouldKillCell(sf::Vector2f pos) const noexcept
{
    int neighbors = 0;

    if (!isCellAlive(pos))
        return (false);
    neighbors = getNbNeighbors(pos);
    if (neighbors == 2 || neighbors == 3)
        return (false);
    return (true);
}

void Board::naturalSelection(std::vector<sf::Vector2f> newCells, std::vector<sf::Vector2f> toDie)
{
    for (const sf::Vector2f &newPos: newCells)
        _map[newPos.y][newPos.x] = ALIVE_CELL;
    for (const sf::Vector2f &diePos: toDie)
        _map[diePos.y][diePos.x] = DEAD_CELL;
}

int Board::evolve(int generation)
{
    std::vector<sf::Vector2f> newCells = {};
    std::vector<sf::Vector2f> toDie = {};
    sf::Vector2f pos = {0, 0};

    for (std::string &row: _map) {
        pos.x = 0;
        for (const char &cell: row) {
            (void)cell;
            if (shouldCreateCell(pos))
                newCells.push_back(pos);
            else if (shouldKillCell(pos))
                toDie.push_back(pos);
            pos.x++;
        }
        pos.y++;
    }
    this->naturalSelection(newCells, toDie);
    return (generation + 1);
}

void Board::setCellSize(int size)
{
    _cellSize = size;
    _rect.setSize(sf::Vector2f(size, size));
}
int Board::getCellSize(void) const { return (_cellSize); }

void Board::setOffset(int offset) { _offset = offset; }
int Board::getOffset(void) const { return (_offset); }
