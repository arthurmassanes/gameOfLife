/*
** ARTHUR MASSANES PROJECT, 2020
** gameoflife
** File description:
** board class
*/

#include "Board.hpp"

Board::Board(void)
{
    sf::Color color = sf::Color::Green;

    for (int y = 0; y < BOARD_SIZE; y++) {
        _map.push_back("");
        for (int x = 0; x < BOARD_SIZE; x++)
            _map[y] += " ";
    }
    _rect.setFillColor(_cellColor);
    _rect.setSize(sf::Vector2f(_cellSize, _cellSize));
    _generation = 0;
    _font.loadFromFile(FONT);
    _savedText = sf::Text(SAVED_TEXT, _font);
    _saveOpacity = 10;
    color.a = _saveOpacity;
    _savedText.setFillColor(color);
    _savedText.setPosition(sf::Vector2f({ 10 , 10 }));
    _savedText.setCharacterSize(24);
    std::cout << _saveOpacity << "\n";
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

    _fileName = fileName;
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
    _mapSave = std::vector<std::string>(_map);
    file.close();
    return (true);
}

bool Board::writeToFile(void)
{
    std::ofstream file(_fileName);
    std::string line;

    if (!file) {
        std::cerr << "Cannot write file\n";
        return (false);
    }
    for (const std::string &line : _map)
        file << line << "\n";
    file.close();
    _mapSave = _map;
    _saveOpacity = 250;
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
    sf::Color textColor = _savedText.getFillColor();

    if (_saveOpacity >= 10) {
        _saveOpacity -= 7;
        textColor.a = _saveOpacity;
    }
    _savedText.setFillColor(textColor);
    if (_cellColor.r >= 250)
        _reverseColor = true;
    else if (_cellColor.r <= 100)
        _reverseColor = false;
    _cellColor.r += off;
    _rect.setFillColor(_cellColor);
}

void Board::clear(void)
{
    for (std::string &line: _map)
        std::replace(line.begin(), line.end(), ALIVE_CELL , DEAD_CELL);
}

void Board::draw(sf::RenderWindow *window)
{
    sf::Vector2f pos = { 0, 0 };
    sf::RectangleShape _grid;

    _grid.setSize(sf::Vector2f(2, 2));
    _grid.setFillColor(sf::Color::Black);
    this->animateColor();
    _nbCells = 0;
    for (const std::string &row: _map) {
         pos.x = 0 + _offset;
        for (const char &c: row) {
            if (c != DEAD_CELL) {
                _nbCells++;
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
    window->draw(_savedText);
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
    std::vector<sf::Vector2f> neighbors;
        // top row
    neighbors.push_back(sf::Vector2f({ pos.x - 1, pos.y - 1 }));
    neighbors.push_back(sf::Vector2f({ pos.x, pos.y - 1 }));
    neighbors.push_back(sf::Vector2f({ pos.x + 1, pos.y - 1 }));

        // cell row
    neighbors.push_back(sf::Vector2f({ pos.x - 1, pos.y }));
    neighbors.push_back(sf::Vector2f({ pos.x + 1, pos.y }));

        // bottom row
    neighbors.push_back(sf::Vector2f({ pos.x - 1, pos.y + 1 }));
    neighbors.push_back(sf::Vector2f({ pos.x, pos.y + 1 }));
    neighbors.push_back(sf::Vector2f({ pos.x + 1, pos.y + 1 }));

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

int Board::evolve(void)
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
    _generation++;
    return (_generation);
}

void Board::setCellSize(int size)
{
    _cellSize = size;
    _rect.setSize(sf::Vector2f(size, size));
}
int Board::getCellSize(void) const { return (_cellSize); }

void Board::setOffset(int offset) { _offset = offset; }
int Board::getOffset(void) const { return (_offset); }

int Board::getNbCells(void) const { return (_nbCells); }

std::string Board::getFileName(void) const { return (_fileName); }

void Board::reInitMap(void)
{
    _map = _mapSave;
    _generation = 0;
}

void Board::click(sf::Vector2f pos, bool hasShift)
{
    int x = (pos.x - _offset) / _cellSize;
    int y = (pos.y) / _cellSize;
    bool isThisCellAlive = isCellAlive(sf::Vector2f(x, y));

    if (x <= 0 || pos.x <= 0 || pos.y <= 0
        || y > getHeight() || x > getWidth(y)) {
        return;
    } else if (!isThisCellAlive) {
        _map[y][x] = ALIVE_CELL;
        std::cout << "Cell added at " << x << "-" << y << "\n";
    } else if (!hasShift)
        _map[y][x] = DEAD_CELL;
}

int Board::getGeneration(void) const { return (_generation); }
void Board::setGeneration(int gen) { _generation = gen; }
