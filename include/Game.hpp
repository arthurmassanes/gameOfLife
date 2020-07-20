
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
#include <SFML/System.hpp>

#include "Board.hpp"
#include "Error.hpp"
#include "Toolbar.hpp"

#define WIDTH 1000
#define HEIGHT 1000
#define FPS 15

#define DEFAULT_MAP "maps/default.map"
#define NAME "Game of Life"

class Game
{
    Board _board;
    sf::RenderWindow *_window;
    sf::Keyboard _keyboard;
    Toolbar *_toolbar;
    bool _paused = true;
    int _generation = 0;
public:
    Game(sf::RenderWindow *win, std::string mapFile);
    ~Game(void);
    void run(void);
    void pollEvent(void);
    bool mouseClicked(sf::Event &);
};


#endif
