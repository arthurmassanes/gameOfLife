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
    _toolbar = new Toolbar(sf::Color(191, 191, 191, 200), _board.getFileName());
}

Game::~Game(void)
{
    delete _toolbar;
}

bool Game::mouseClicked(sf::Event &event)
{
    return (event.type == sf::Event::MouseButtonPressed
            && event.mouseButton.button == sf::Mouse::Left);
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
        _board.setOffset(_board.getOffset() + (cellSize * 2));
    if (_keyboard.isKeyPressed(sf::Keyboard::Right))
        _board.setOffset(_board.getOffset() - (cellSize * 2));
    if (_keyboard.isKeyPressed(sf::Keyboard::BackSpace)) {
        _board.reInitMap();
        _paused = true;
    }
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window->close();
        else if (event.type == sf::Event::KeyReleased
                 && event.key.code == sf::Keyboard::Space)
            _paused = !_paused;
        else if (this->mouseClicked(event)) {
            _board.click(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
        }
    }
}

void Game::run(void)
{
    while (_window->isOpen()) {
        _window->clear(sf::Color::White);
        this->pollEvent();
        _board.draw(_window);
        _toolbar->draw(_window);
        _toolbar->update(_board.getGeneration(), _board.getNbCells());
        _window->display();
        try {
            if (!_paused)
                _board.evolve();
        } catch (const Error &e) {
            e.printErr();
        }
    }
}
