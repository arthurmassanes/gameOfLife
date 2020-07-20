/*
** EPITECH PROJECT, 2020
** gameOfLife
** File description:
** toolbar class
*/

#include "Toolbar.hpp"

Toolbar::Toolbar(void): Toolbar(sf::Color::Black)
{
}

Toolbar::Toolbar(sf::Color color)
{
    _barColor = color;
    _bar.setFillColor(color);
    _bar.setSize(sf::Vector2f(1000, 200));
    _bar.setOutlineThickness(5);
    _bar.setOutlineColor(sf::Color::Black);
    _bar.setPosition(0, 800);
    _generationNb = 0;
    loadInstructions();
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

    _keysList = sf::Text(KEYS_TEXT, _font);
    _keysList.setFillColor(sf::Color(0, 0, 0, 100));
    _keysList.setPosition(sf::Vector2f({ .x = _bar.getPosition().x + 20, .y = _bar.getPosition().y + 75}));
    _keysList.setCharacterSize(18);
    _keysList.setStyle(sf::Text::Italic);
}

void Toolbar::update(int generation, int cells)
{
    _generationNb = generation;
    _generation.setString(GENERATION_TEXT + std::to_string(_generationNb));
    _cells.setString(CELLS_TEXT + std::to_string(cells));
}

void Toolbar::draw(sf::RenderWindow *window)
{
    window->draw(_bar);
    window->draw(_generation);
    window->draw(_keysList);
    window->draw(_cells);
}
