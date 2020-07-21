/*
** ARTHUR MASSANES PROJECT, 2020
** gamoflife
** File description:
** start animation
*/

#include "StartupAnimation.hpp"

StartupAnimation::StartupAnimation(void): _textColor(sf::Color::Black), _fadeColor(sf::Color::Black)
{
    if (!_font.loadFromFile(MAIN_FONT))
        throw Error("Cannot create startup font", "StartupAnimation::StartupAnimation");
    _text = sf::Text(TEXT, _font);
    _text.setPosition(sf::Vector2f(50, 800));
    _text.setCharacterSize(50);
    _text.setFillColor(_textColor);

    _titleColor = sf::Color::Blue;
    _title = sf::Text(TITLE, _font);
    _title.setPosition(sf::Vector2f(50, 500));
    _title.setCharacterSize(75);
    _title.setFillColor(_titleColor);

    _fadeColor.a = 10;
    _fade.setPosition(sf::Vector2f(0, 0));
    _fade.setSize(sf::Vector2f(1000, 1000));
    _fade.setFillColor(_fadeColor);
}

bool StartupAnimation::isDone(void)
{
    return (_hasPressedKey && _isDone);
}

void StartupAnimation::pollEvent(sf::RenderWindow *window)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed)
            _hasPressedKey = true;
        if (event.type == sf::Event::Closed
                 || (event.type == sf::Event::KeyPressed
                     && event.key.code == sf::Keyboard::Escape))
            window->close();
    }
}

void StartupAnimation::animateText(sf::RenderWindow *window)
{
    int off = _reverseColor ? -3 : 3;

    _textColor.a -= 10;
    _text.setFillColor(_textColor);
    _titleColor.r += off;
    if (_titleColor.r >= 250)
        _reverseColor = true;
    else if (_titleColor.r <= 100)
        _reverseColor = false;
    _title.setFillColor(_titleColor);
    if (_hasPressedKey)
        _fadeColor.a += _opacityOffset;
    _fade.setFillColor(_fadeColor);
    window->draw(_fade);
    if (!_hasPressedKey) {
        window->draw(_text);
        window->draw(_title);
    }
    _isDone = _fadeColor.a <= 5;
    _opacityOffset = _fadeColor.a >= 250 ? (_opacityOffset * -1): _opacityOffset;
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
