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

class Board
{
    // TODO read from file
    std::vector<std::string> _map = {
        "   O   ",
        "  O    ",
        "       "
    };
public:
    Board(void);
};


#endif
