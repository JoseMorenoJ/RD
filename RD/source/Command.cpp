//
//  Command.cpp
//  RecklessDriver
//
//  Created by José Moreno on 13/07/19.
//  Copyright (c) 2019 José Moreno. All rights reserved.
//

#include "Command.h"

Command::~Command(){}

void MoveLeft::execute(GameObject& GO)
{
    GO.SetX( GO.GetX() + 1);
}

void execute(GameObject& GO)
{
    GO.SetX( GO.GetX() - 1);
}