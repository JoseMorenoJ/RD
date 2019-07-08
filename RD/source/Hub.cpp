/*
	class Hub: it displays the game information after every iteration.

*/

#include <vector>
#include <random>
#include <iostream>
#include <thread>

#include "Hub.h"
#include "GameManager.h"
#include "SideObject.h"
#include "System.h"

//**************************************************************************************
//default Constructor
Hub::Hub(){}

//**************************************************************************************
//default Destructor
Hub::~Hub(){}

//**************************************************************************************
//Rewrite the screen with the new info.
void Hub::Update(ObjectPool &pool, Player &player)
{
    //Clear the screen
    System::pause();
	DisplayGameObjects(pool);

	//Show the cash from the GM and the health from the player
	ShowStats(player);

	return;
}

//**************************************************************************************
//Shows that the player is driving on the screen.
void Hub::Driving() const
{
	std::cout << "\nPlayer is driving\n";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	std::cout << std::endl;
}

//**************************************************************************************
//Screen called after the game is over, it shows the total points obtained.
void Hub::ShowEndGame(int tCash) const
{
	//TODO: show a list of the crashes

	std::cout << "Total cash accumulated: $" << tCash << std::endl;
}

//**************************************************************************************
//Display all the objects in the pool.
void Hub::DisplayGameObjects(ObjectPool& pool)
{
	for (const auto *p : pool.GetvGameObjects())
	{
		if (p != nullptr) //check that the Game Object is valid.
		{
			if (p->GetTag() == "Side Object")
			{
				std::cout << p->GetName() << "\t[X]";
			}
			if (p->GetTag() == "Traffic Car")
			{
				std::cout << "\t\t\t[O]" << p->GetName();
			}
		}
		std::cout << std::endl;
	}
	return;
}

//**************************************************************************************
//Show the health points and the accumulated money of the player in the screen.
void Hub::ShowStats(const Player &player)
{
	std::cout << "\n***************************************** Cash: $";
	std::cout << GameManager::GetInstance().GetCash() << "\tHealth: ";
	std::cout << std::max(player.GetHealth(), 0) << std::endl; //Never print less than 0
}

