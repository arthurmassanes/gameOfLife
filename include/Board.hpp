/*
** ARTHUR MASSANES PROJECT, 2020
** gameoflife
** File description:
** main
*/

#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <vector>
#include <iostream>

#define BOARD_SIZE 100

class Board
{
    // TODO read from file
    std::vector<std::string> _map;
public:
    Board(void);
    void dump(void);
    bool loadFromFile(std::string file);
};


#endif
