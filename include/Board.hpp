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

#include "Error.hpp"

#define BOARD_SIZE 100
#define DEAD_CELL ' '
#define ALIVE_CELL 'O'

class Board
{
    int _cellSize = 10;
    std::vector<std::string> _map;
    sf::RectangleShape _rect;
    bool _isGridVisible = true;
    sf::Color _cellColor = sf::Color::Blue;
    bool _reverseColor = false;
    int _offset = 10;
public:
    Board(void);
    void draw(sf::RenderWindow *);
    void dump(void);
    bool loadFromFile(std::string fileName);

    // Board grid
    void setGridVisibility(bool);
    void toggleGridVisibility(void);
    void animateColor(void);

    // Its evolving
    void evolve(void);
    unsigned int getNbNeighbors(sf::Vector2f) const;
    bool isCellAlive(sf::Vector2f) const;
    bool shouldCreateCell(sf::Vector2f) const noexcept;
    bool shouldKillCell(sf::Vector2f) const noexcept;
    void naturalSelection(std::vector<sf::Vector2f>, std::vector<sf::Vector2f>);

    // Getters
    bool isGridVisible(void) const;
    int getHeight(void) const;
    // This one needs a y parameter
    // since some lines are longer than others
    int getWidth(int y) const;
    bool isInvalidPos(sf::Vector2f) const noexcept;
    void setCellSize(int size);
    int getCellSize(void) const;
    void setOffset(int);
    int getOffset(void) const;

};


#endif
