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

#define KEYS_TEXT "[Space] Toggle pause\
\n[Left] Move left\n[Right] Move right\
\n[Up] Zoom in\
\n[Down] Zoom out\
\n\n[Return] Board save                           \
\n[BackSpace] Board reset\
\n[B] Clear board\
\n\n[G] Toggle grid\
\n[Left Shift] Pencil mode"

#define HELP_TEXT "Help"

#define X_OFFSET 15
#define Y_OFFSET 3
#define TEXT_OFFSET 400
#define POPUP_OFFSET 400

class HelpButton
{
    int _buttonWidth;
    int _buttonHeight;
    int _popupWidth;
    int _popupHeight;
    sf::RectangleShape _background;
    sf::RectangleShape _popup;
    sf::Text _helpText;
    sf::Font &_font;
    sf::Text _keysList;
    bool _isHoveringButton = false;
public:
    HelpButton(sf::Font &);

    // needs mouse pos
    void update(sf::RenderWindow *);
    void setPosition(sf::Vector2f);
    void draw(sf::RenderWindow *);
};


#endif
