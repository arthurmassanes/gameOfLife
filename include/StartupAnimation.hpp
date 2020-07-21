/*
** ARTHUR MASSANES PROJECT, 2020
** gameoflife
** File description:
** start animation
*/

#ifndef STARTUPANIMATION_HPP_
#define STARTUPANIMATION_HPP_

#include "Game.hpp"
#include "Error.hpp"

#define TEXT "press any key to start..."
#define TITLE "GAME OF LIFE"
#define MAIN_FONT "fonts/main.ttf"

class StartupAnimation
{
    bool _hasPressedKey = false;
    bool _isDone = false;
    bool _reverseColor = false;
    sf::RectangleShape _fade;
    sf::Font _font;
    sf::Text _title;
    sf::Color _titleColor;
    sf::Text _text;
    sf::Color _textColor;
    sf::Color _fadeColor;
    int _opacityOffset = 25;
public:
    StartupAnimation(void);
    void play(sf::RenderWindow *);
    bool isDone(void);
    void pollEvent(sf::RenderWindow *);
    void animateText(sf::RenderWindow *);
};


#endif
