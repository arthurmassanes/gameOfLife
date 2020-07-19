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
    _rect.setFillColor(sf::Color::Blue);
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

void Board::draw(sf::RenderWindow *window)
{
    sf::Vector2f pos = {0, 0};
    sf::RectangleShape _grid;

    _grid.setSize(sf::Vector2f(2, 2));
    _grid.setFillColor(sf::Color::Red);
    for (const std::string &row: _map) {
         pos.x = 0;
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
