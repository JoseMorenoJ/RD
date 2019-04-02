/*
	class Sedan: behaviour of the traffic car type Sedan.
		Inherits from TrafficCar.
*/

#include <iostream>
//QSDFQSDFQSDF

#include "Sedan.h"
#include "Player.h"
#include "params.h"

namespace RecklessDriver {

	//**************************************************************************************
	//This initializes the values with the constructor from TrafficCar
	Sedan::Sedan() : TrafficCar(params::SEDAN_DAMAGE, params::SEDAN_CASH)
	{
		SetName("Sedan");
	}

	//**************************************************************************************
	//default Destructor
	Sedan::~Sedan(){ std::cout << "~Sedan()" << std::endl; }

	//**************************************************************************************
	//Behaviour after a collision.
	void Sedan::OnCollision(const GameObject &other)
	{
		if (other.GetName() == "Player")
		{
			Player &p = (Player&)other;
			if (this->IsCrashed()) //2nd collision
			{
				this->Sparks();
				std::cout << "### EXTRA COLLISION -> Sedan" << std::endl;
				p.ApplyDamage(this->GetDamage(), 2*this->GetCash()); //Double cash
			}
			else //1st collision
			{
				this->Sparks();
				std::cout << "### COLLISION -> Sedan" << std::endl;
				this->Crashed();
				this->SetName("bumped Sedan");
				p.ApplyDamage(this->GetDamage(), this->GetCash());
			}
		}
		return;
	}

}//namespace RecklessDriver
