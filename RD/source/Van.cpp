/*
	class Van: behaviour of the traffic car type Van.
		Inherits from TrafficCar.
*/

#include <iostream>

#include "Van.h"
#include "Player.h"
#include "params.h"

//**************************************************************************************
//This initializes the values with the constructor from TrafficCar
Van::Van() : TrafficCar(params::VAN_DAMAGE, params::VAN_CASH)
{
	setName("Van");
}

//**************************************************************************************
//default Destructor
Van::~Van() { std::cout << "~Van()" << std::endl; }

//**************************************************************************************
//Behaviour after a collision.
void Van::onCollision(const GameObject &other)
{
	if (other.getName() == "Player")
	{
		Player &p = (Player&)other;
		if (this->isCrashed()) //2nd collision
		{
			this->sparks();
			std::cout << "### EXTRA COLLISION -> Van" << std::endl;
			p.applyDamage(this->getDamage(), 2*this->getCash()); //Double cash
		}
		else //1st collision
		{
			this->sparks();
			std::cout << "### COLLISION -> Van" << std::endl;
			this->crashed();
			this->setName("bumped Van");
			p.applyDamage(this->getDamage(), this->getCash());
		}
	}
	return;
}
