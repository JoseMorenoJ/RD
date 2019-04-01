/*
	class Van: behaviour of the traffic car type Van.
		Inherits from TrafficCar.
*/

#include <iostream>

#include "Van.h"
#include "Player.h"
#include "params.h"

namespace RecklessDriver {

	//**************************************************************************************
	//This initializes the values with the constructor from TrafficCar
	Van::Van() : TrafficCar(params::VAN_DAMAGE, params::VAN_CASH)
	{
		SetName("Van");
	}

	//**************************************************************************************
	//default Destructor
	Van::~Van() { std::cout << "~Van()" << std::endl; }

	//**************************************************************************************
	//Behaviour after a collision.
	void Van::OnCollision(const GameObject &other)
	{
		if (other.GetName() == "Player")
		{
			Player &p = (Player&)other;
			if (this->IsCrashed()) //2nd collision
			{
				this->Sparks();
				std::cout << "### EXTRA COLLISION -> Van" << std::endl;
				p.ApplyDamage(this->GetDamage(), 2*this->GetCash()); //Double cash
			}
			else //1st collision
			{
				this->Sparks();
				std::cout << "### COLLISION -> Van" << std::endl;
				this->Crashed();
				this->SetName("bumped Van");
				p.ApplyDamage(this->GetDamage(), this->GetCash());
			}
		}
		return;
	}

}//namespace RecklessDriver
