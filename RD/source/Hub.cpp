#pragma once
/*
	class Hub: it displays the game information after every iteration.

*/

#include <vector>
#include <random>
#include <iostream>

#include "Hub.h"


namespace RecklessDriver {

	//default Constructor
	Hub::Hub(){}

	//default Destructor
	Hub::~Hub(){}

	//Rewrite the screen with the new info.
	void Hub::update(ObjectPool * pPool, Player * pPlayer)
	{
		//Clear the screen
		system("cls");

		//TODO: Unite the functions to take Game Objects undistinctly.
		DisplaySideObjects(pPool);
		DisplayTraffic(pPool);

		//Show the cash from the GM and the health from the player

		//Show: Player is driving

		return;
	}

	//Display the side object
	void Hub::DisplaySideObjects(ObjectPool * pPool)
	{
		std::cout << "\nSide OBJECTS" << std::endl;
		for (const auto *p : * pPool->GetvSideObjects())
		{
			std::cout << p->GetName() << "\t";
		}
		std::cout << std::endl;
	}

	//Display de traffic cars
	void Hub::DisplayTraffic(ObjectPool * pPool)
	{
		std::cout << "\nTraffic OBJECTS" << std::endl;
		for (const auto *p : * pPool->GetvTraffic())
		{
			std::cout << p->GetName() << "\t";
		}
		std::cout << std::endl;
	}

}//namespace RecklessDriver
