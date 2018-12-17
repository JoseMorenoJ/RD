/*
	Object Oriented analysis, design and programming.
		Project: Reckless Driver game development.

	main program: it launches the Reckless Driver game from the GameManager class.

	17 December 2018
	José Moreno
*/

#include "GameManager.h"

using namespace RecklessDriver;

int main()
{
	GameManager::GetInstance().NewGame();

	return 0;
}