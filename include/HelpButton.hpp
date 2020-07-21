/*
** ARTHUR MASSANES PROJECT, 2020
** gameOfLif
** File description:
** help button
** should show help when hovered
*/

#ifndef HELPBUTTON_HPP_
#define HELPBUTTON_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class HelpButton
{
    sf::RectangleShape _background;
    sf::Text _helpText;
    sf::Font &_font;
public:
    HelpButton(sf::Font &);
    void draw(void);
};


#endif
