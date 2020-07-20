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
    sf::Font _font;
    sf::Text _title;
    sf::Text _text;
    sf::Color _textColor;
public:
    StartupAnimation(void);
    void play(sf::RenderWindow *);
    bool isDone(void);
    void pollEvent(sf::RenderWindow *);
    void animateText(sf::RenderWindow *);
};


#endif
