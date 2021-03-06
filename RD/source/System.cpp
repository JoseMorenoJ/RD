//
//  System.cpp
//  RecklessDriver
//
//  Created by José Moreno on 08/07/19.
//  Copyright (c) 2019 José Moreno. All rights reserved.
//

#include <iostream>
#include <cstdlib>

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
}