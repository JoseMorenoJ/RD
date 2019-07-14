//
//  InputHandler.cpp
//  RecklessDriver
//
//  Created by José Moreno on 14/07/19.
//  Copyright (c) 2019 José Moreno. All rights reserved.
//

#include <SFML/Window/Keyboard.hpp>

#include "InputHandler.h"

void InputHandler::handleInput()
{
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) ) return _left;
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) ) return _right;
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) ) return _down;
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) ) return _up;
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) ) return _select;
    
    // Nothing pressed, so do nothing.
    return nullptr;
}
