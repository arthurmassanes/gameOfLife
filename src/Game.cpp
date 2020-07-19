/*
** EPITECH PROJECT, 2020
** gameOfLife
** File description:
** game class implementation
*/

#include "Game.hpp"

Game::Game(sf::RenderWindow *window)
{
    _window = window;
    if (!_board.loadFromFile("basic.map"))
        throw Error("Cannot build board", "Game::Game");
    _board.dump();
}

void Game::run(void)
{
    while (_window->isOpen()) {
        _window->clear();
        _window->display();
    }
}
