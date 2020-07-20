/*
** ARTHUR MASSANES PROJECT, 2020
** gameoflife
** File description:
** toolbar
*/

#ifndef TOOLBAR_HPP_
#define TOOLBAR_HPP_

#include "Board.hpp"
#define FONT "fonts/font.ttf"
#define KEYS_TEXT "[Left] Move left\n[Right] Move right\
\n[Up] Zoom in\
\n[Down] Zoom out\
\n[Space] Toggle pause"

class Toolbar
{
    sf::RectangleShape _bar;
    sf::Color _barColor;
    sf::Font _font;
    sf::Text _generation;
    sf::Text _keysList;
    int _generationNb;
public:
    Toolbar(void);
    Toolbar(sf::Color);
    void draw(sf::RenderWindow *);
    void update(int);
    void loadInstructions(void);
};


#endif
