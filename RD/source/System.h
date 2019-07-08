//
//  System.h
//  RecklessDriver
//
//  Created by José Moreno on 07/07/19.
//  Copyright (c) 2019 José Moreno. All rights reserved.
//

#ifndef RecklessDriver_System_h
#define RecklessDriver_System_h

namespace System {

#ifdef _WIN32
// Definitions for Windows commands
void clear()
{
    system("cls");
}
void pause()
{
    system("pause");
}

#elif __APPLE__
// Definitions for MacOS commands
void clear()
{
    system("clear");
}
void pause()
{
    system("read -n 1 -s");
}
#endif
} //namespace System
#endif
