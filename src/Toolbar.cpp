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
    _font.loadFromFile(FONT);
    _generation = sf::Text("Generation: ", _font);
    _generation.setFillColor(sf::Color::Black);
    _generation.setPosition(sf::Vector2f({ .x = _bar.getPosition().x + 20, .y = _bar.getPosition().y + 10}));
    _generation.setCharacterSize(24);
}

void Toolbar::update(int generation)
{
    _generationNb = generation;
    _generation.setString("Generation: " + std::to_string(_generationNb));
}

void Toolbar::draw(sf::RenderWindow *window)
{
    window->draw(_bar);
    window->draw(_generation);
}
