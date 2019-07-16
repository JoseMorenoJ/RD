//
//  InputHandler.cpp
//  RecklessDriver
//
//  Created by José Moreno on 14/07/19.
//  Copyright (c) 2019 José Moreno. All rights reserved.
//

#include <SFML/Window/Keyboard.hpp>

#include "InputHandler.h"

InputHandler::InputHandler()
{
    //TODO instanciate the Commands
    _left = new MoveLeft;
    _right = new MoveRight;
    _up = nullptr;
    _down = nullptr;
    _select = nullptr;
}

void InputHandler::handleInput(GameObject* pPlayer)
{
    Command* cmd = getAction();
    if(cmd) cmd->execute(*pPlayer);
}

Command* InputHandler::getAction()
{
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) ) return _left;
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right) ) return _right;
    
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down) ) return nullptr;
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up) ) return nullptr;
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Enter) ) return nullptr;
    
    return nullptr;
}
