//
//  Command.cpp
//  RecklessDriver
//
//  Created by José Moreno on 13/07/19.
//  Copyright (c) 2019 José Moreno. All rights reserved.
//

#include "Command.h"
#include "params.h"

Command::~Command(){}

void MoveLeft::execute(GameObject& GO)
{
    if (GO.getX() > 0)
    {
        GO.setX( GO.getX() - 1);
    }

}

void MoveRight::execute(GameObject& GO)
{
    if (GO.getX() < params::SCREEN_HOR - 1)
    {
        GO.setX( GO.getX() + 1);
    }
}