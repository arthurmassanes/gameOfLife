/*
** EPITECH PROJECT, 2020
** gameOfLife
** File description:
** game class implementation
*/

#include "Game.hpp"

Game::Game(sf::RenderWindow *window, std::string mapFile)
{
    _window = window;
    if (!_board.loadFromFile(mapFile))
        throw Error("Cannot build board", "Game::Game");
    window->setFramerateLimit(FPS);
}

void Game::pollEvent(void)
{
    sf::Event event;

    if (_keyboard.isKeyPressed(sf::Keyboard::Escape)) {
        _window->close();
        return;
    }
    if (_keyboard.isKeyPressed(sf::Keyboard::Up))
        _board.setCellSize(_board.getCellSize() + 1);
    if (_keyboard.isKeyPressed(sf::Keyboard::Down))
        _board.setCellSize(_board.getCellSize() - 1);
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window->close();
    }
}

void Game::run(void)
{
    while (_window->isOpen()) {
        _window->clear(sf::Color::White);
        this->pollEvent();
        _board.draw(_window);
        _window->display();
        try {
            _board.evolve();
        } catch (const Error &e) {
            e.printErr();
        }
    }
}
