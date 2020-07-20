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
    _toolbar = new Toolbar(sf::Color(191, 191, 191, 200));
}

Game::~Game(void)
{
    delete _toolbar;
}

void Game::pollEvent(void)
{
    sf::Event event;
    auto cellSize = _board.getCellSize();

    if (_keyboard.isKeyPressed(sf::Keyboard::Escape)) {
        _window->close();
        return;
    }
    if (_keyboard.isKeyPressed(sf::Keyboard::Up))
        _board.setCellSize(cellSize + 2);
    if (_keyboard.isKeyPressed(sf::Keyboard::Down))
        _board.setCellSize(cellSize - 2);
    cellSize = _board.getCellSize();
    if (_keyboard.isKeyPressed(sf::Keyboard::Left))
        _board.setOffset(_board.getOffset() + cellSize);
    if (_keyboard.isKeyPressed(sf::Keyboard::Right))
        _board.setOffset(_board.getOffset() - cellSize);

    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window->close();
    }
}

void Game::run(void)
{
    int generation = 0;

    while (_window->isOpen()) {
        _window->clear(sf::Color::White);
        this->pollEvent();
        _board.draw(_window);
        _toolbar->draw(_window);
        _toolbar->update(generation);
        _window->display();
        try {
            _board.evolve();
            generation++;
        } catch (const Error &e) {
            e.printErr();
        }
    }
}
