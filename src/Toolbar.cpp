/*
** ARTHUR MASSANES PROJECT, 2020
** gameOfLife
** File description:
** toolbar class
*/

#include "Toolbar.hpp"

Toolbar::Toolbar(void): Toolbar(sf::Color::Black)
{
}

Toolbar::Toolbar(sf::Color color, std::string fileName)
{
    _barColor = color;
    _bar.setFillColor(color);
    _bar.setSize(sf::Vector2f(1000, 200));
    _bar.setOutlineThickness(5);
    _bar.setOutlineColor(sf::Color::Black);
    _bar.setPosition(0, 800);
    _generationNb = 0;
    _fileName = std::string(fileName);
    _helpButton = new HelpButton(_font);
    _helpButton->setPosition(sf::Vector2f(_bar.getPosition().x + 25, _bar.getPosition().y + 100));
    loadInstructions();
}

Toolbar::Toolbar(sf::Color color): Toolbar(color, "Unkown file")
{
}

Toolbar::~Toolbar(void)
{
    delete _helpButton;
}

void Toolbar::loadInstructions(void)
{
    _font.loadFromFile(FONT);
    _generation = sf::Text(GENERATION_TEXT, _font);
    _generation.setFillColor(sf::Color::Black);
    _generation.setPosition(sf::Vector2f({ .x = _bar.getPosition().x + 20, .y = _bar.getPosition().y + 10}));
    _generation.setCharacterSize(24);

    _cells = sf::Text(CELLS_TEXT, _font);
    _cells.setFillColor(sf::Color::Black);
    _cells.setPosition(sf::Vector2f({ .x = _bar.getPosition().x + 20, .y = _bar.getPosition().y + 40}));
    _cells.setCharacterSize(24);

    _fileNameText = sf::Text(_fileName, _font);
    _fileNameText.setFillColor(sf::Color::Blue);
    _fileNameText.setPosition(sf::Vector2f({ .x = _bar.getPosition().x + 700, .y = _bar.getPosition().y + 10}));
    _fileNameText.setCharacterSize(16);

    _pause = sf::Text(PAUSE_TEXT, _font);
    _pause.setFillColor(sf::Color::Red);
    _pause.setPosition(sf::Vector2f({ .x = _bar.getPosition().x , .y = _bar.getPosition().y - 35}));
    _pause.setCharacterSize(20);
}

void Toolbar::update(int generation, int cells)
{
    _generationNb = generation;
    _generation.setString(GENERATION_TEXT + std::to_string(_generationNb));
    _cells.setString(CELLS_TEXT + std::to_string(cells));
    _helpButton->update(_win);
}

void Toolbar::draw(sf::RenderWindow *window, bool isPause)
{
    _win = window;
    window->draw(_bar);
    window->draw(_generation);
    window->draw(_cells);
    window->draw(_fileNameText);
    if (isPause)
        window->draw(_pause);
    _helpButton->draw(window);
}
