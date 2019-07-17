/*
	class FireHydrant: behaviour of the side object of the type fire hydrant.
		Inherits from SideObject.
*/

#include <iostream>

#include "FireHydrant.h"
#include "Player.h"
#include "params.h"

//**************************************************************************************
//Constructor
FireHydrant::FireHydrant(): SideObject(params::FIREHYDRANT_DAMAGE, params::FIREHYDRANT_CASH)
{
	setName("Fire Hydrant");
}

//**************************************************************************************
//default Destructor
FireHydrant::~FireHydrant() { std::cout << "~FireHydrant()" << std::endl; }

//**************************************************************************************
//Specifies the behaviour when two GameObject collide
void FireHydrant::onCollision(const GameObject &other)
{
	if (other.getName() == "Player")
	{
		Player &p = (Player &)other;
		if (this->isCrashed()) //2nd collision
		{
			//Nothing happend in a second collision with a Side Object
			std::cout << "### Run over a " << this->getName() << std::endl;
		}
		else //1st collision
		{
			std::cout << "### COLLISION -> Fire Hydrant" << std::endl;
			this->_bCrashed = true;
			this->setName("water fountain");
			this->fountain();
			p.applyDamage(this->getDamage(), this->getCash());
		} 
	}
	return;
}

//**************************************************************************************
//
void FireHydrant::fountain()
{
	std::cout << "WATER FOUNTAIN FROM THE FIRE HYDRANT!!" << std::endl;
}