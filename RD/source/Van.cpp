/*
	class Van: behaviour of the traffic car type Van.
		Inherits from TrafficCar.
*/

#include <iostream>

#include "Van.h"
#include "Player.h"

namespace RecklessDriver {

	//This initializes the values with the constructor from TrafficCar
	Van::Van(int damage, int cash) :TrafficCar(damage, cash) 
	{
		SetName("Van");
	}

	//default Destructor
	Van::~Van() {}

	void Van::OnCollision(const GameObject &other)
	{
		Player &p = (Player&)other;
		std::cout << "### COLLISION -> Van" << std::endl;
		p.ApplyDamage(this->GetDamage(), this->GetCash());
		this->Sparks();
		return;
	}

}//namespace RecklessDriver
