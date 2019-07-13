//
//  Command.h
//  RecklessDriver
//
//  Created by José Moreno on 13/07/19.
//  Copyright (c) 2019 José Moreno. All rights reserved.
//

#ifndef __RecklessDriver__Command__
#define __RecklessDriver__Command__

#include <stdio.h>

#include "GameObject.h"

class Command
{
public:
    virtual ~Command();
    virtual void execute(GameObject &) = 0;
};

class MoveLeft : public Command
{
public:
    virtual void execute(GameObject &);
};

class MoveRight : public Command
{
public:
    virtual void execute(GameObject &);
};

#endif /* defined(__RecklessDriver__Command__) */
