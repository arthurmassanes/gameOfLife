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
    int y = 0;
    int x = 0;

    if (!file) {
        std::cerr << "Could not read file '" << fileName << "'\n";
        return (false);
    }
    while (std::getline(file, line)) {
        x = 0;
        for (const char &c: line) {
            _map[y][x] = c;
            x++;
        }
        y++;
    }
    return (true);
}
