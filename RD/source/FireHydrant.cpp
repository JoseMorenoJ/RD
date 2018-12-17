/*
	class FireHydrant: behaviour of the side object of the type fire hydrant.
		Inherits from SideObject.
*/

#include <iostream>

#include "FireHydrant.h"
#include "Player.h"

namespace RecklessDriver {

	//Constructor
	FireHydrant::FireHydrant(int damage, int cash):SideObject(damage, cash)
	{
		SetName("Fire Hydrant");
	}

	//default Destructor
	FireHydrant::~FireHydrant() {}

	//Specifies the behaviour when two GameObject collide
	void FireHydrant::OnCollision(const GameObject &other)
	{
		if (other.GetName() == "Player")
		{
			Player &p = (Player &)other;
			if (_count == 0)
			{
				std::cout << "### COLLISION -> FireHydrant" << std::endl;
				this->Fountain();
				p.ApplyDamage(this->GetDamage(), this->GetCash());
			}
			else
			{
				std::cout << "### EXTRA COLLISION -> FireHydrant" << std::endl;
				p.ApplyDamage(this->GetDamage(), this->GetCash());
			}
		}
		return;
	}

	void FireHydrant::Fountain()
	{
		std::cout << "WATER FOUNTAIN FROM THE FIRE HYDRANT!!" << std::endl;
	}
}