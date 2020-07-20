/*
** ARTHUR MASSANES PROJECT, 2020
** gamoflife
** File description:
** start animation
*/

#include "StartupAnimation.hpp"

StartupAnimation::StartupAnimation(void): _textColor(sf::Color::Black)
{
    if (!_font.loadFromFile(MAIN_FONT))
        throw Error("Cannot create startup font", "StartupAnimation::StartupAnimation");
    _text = sf::Text(TEXT, _font);
    _text.setPosition(sf::Vector2f(50, 800));
    _text.setCharacterSize(50);
    _text.setFillColor(_textColor);

    _title = sf::Text(TITLE, _font);
    _title.setPosition(sf::Vector2f(50, 500));
    _title.setCharacterSize(75);
    _title.setFillColor(sf::Color::Blue);

}

bool StartupAnimation::isDone(void)
{
    return (_hasPressedKey);
}

void StartupAnimation::pollEvent(sf::RenderWindow *window)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed)
            _hasPressedKey = true;
    }
}

void StartupAnimation::animateText(sf::RenderWindow *window)
{
    _textColor.a -= 10;
    _text.setFillColor(_textColor);
    window->draw(_text);
    window->draw(_title);
}

void StartupAnimation::play(sf::RenderWindow *window)
{
    while (window->isOpen() && !this->isDone()) {
        window->clear(sf::Color::White);
        this->pollEvent(window);
        this->animateText(window);
        window->display();
    }
}
