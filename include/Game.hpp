/*
** ARTHUR MASSANES PROJECT, 2020
** gameOfLife
** File description:
** main game class
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Board.hpp"
#include "Error.hpp"

#define NAME "Game of Life"

class Game
{
    Board _board;
    sf::RenderWindow *_window;
public:
    Game(sf::RenderWindow *win);
    void run(void);
};


#endif
