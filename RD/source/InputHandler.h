//
//  InputHandler.h
//  RecklessDriver
//
//  Created by José Moreno on 14/07/19.
//  Copyright (c) 2019 José Moreno. All rights reserved.
//

#ifndef __RecklessDriver__InputHandler__
#define __RecklessDriver__InputHandler__

#include <stdio.h>

#include "Command.h"

class InputHandler
{
public:
    void handleInput();
    
    //TODO relate keys with actions
    
private:
    Command* _left;
    Command* _right;
    Command* _up;
    Command* _down;
    Command* _select;
    
};

#endif /* defined(__RecklessDriver__InputHandler__) */
