/*
** ARTHUR MASSANES PROJECT, 2020
** gameoflife
** File description:
** main
*/

#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>
#include <fstream>

#define BOARD_SIZE 100
#define DEAD_CELL ' '

class Board
{
    int _cellSize = 20;
    std::vector<std::string> _map;
    sf::RectangleShape _rect;
    bool _isGridVisible = true;
public:
    Board(void);
    void draw(sf::RenderWindow *);
    void dump(void);
    bool loadFromFile(std::string fileName);

    // Board grid
    void setGridVisibility(bool);
    bool isGridVisible(void) const;
    void toggleGridVisibility(void);
};


#endif
