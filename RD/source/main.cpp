/*
	Object Oriented analysis, design and programming.
		Project: Reckless Driver game development.

	main program: it launches the Reckless Driver game from the GameManager class.

	17 December 2018
	José Moreno
*/
#include <iostream>

#include "GameManager.h"

int main()
{
	do
    {
		GameManager::getInstance().newGame();
	}
    while ( GameManager::getInstance().playAgain() );

	std::cout << std::endl;
	std::cout << "Thanks for playing, see you next time!" << std::endl;

	return 0;
}