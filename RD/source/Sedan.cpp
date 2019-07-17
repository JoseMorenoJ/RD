/*
	class Sedan: behaviour of the traffic car type Sedan.
		Inherits from TrafficCar.
*/

#include <iostream>

#include "Sedan.h"
#include "Player.h"
#include "params.h"

//**************************************************************************************
//This initializes the values with the constructor from TrafficCar
Sedan::Sedan() : TrafficCar(params::SEDAN_DAMAGE, params::SEDAN_CASH)
{
	setName("Sedan");
}

//**************************************************************************************
//default Destructor
Sedan::~Sedan(){ std::cout << "~Sedan()" << std::endl; }

//**************************************************************************************
//Behaviour after a collision.
void Sedan::onCollision(const GameObject &other)
{
	if (other.getName() == "Player")
	{
		Player &p = (Player&)other;
		if (this->isCrashed()) //2nd collision
		{
			this->sparks();
			std::cout << "### EXTRA COLLISION -> Sedan" << std::endl;
			p.applyDamage(this->getDamage(), 2 * this->getCash()); //Double cash
		}
		else //1st collision
		{
			this->sparks();
			std::cout << "### COLLISION -> Sedan" << std::endl;
			this->_bCrashed = true;
			this->setName("bumped Sedan");
			p.applyDamage(this->getDamage(), this->getCash());
		}
	}
	return;
}
