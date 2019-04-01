/*
	class FireHydrant: behaviour of the side object of the type fire hydrant.
		Inherits from SideObject.
*/

#include <iostream>

#include "FireHydrant.h"
#include "Player.h"
#include "params.h"

namespace RecklessDriver {

	//**************************************************************************************
	//Constructor
	FireHydrant::FireHydrant(): SideObject(params::FIREHYDRANT_DAMAGE, params::FIREHYDRANT_CASH)
	{
		SetName("Fire Hydrant");
	}

	//**************************************************************************************
	//default Destructor
	FireHydrant::~FireHydrant() { std::cout << "~FireHydrant()" << std::endl; }

	//**************************************************************************************
	//Specifies the behaviour when two GameObject collide
	void FireHydrant::OnCollision(const GameObject &other)
	{
		if (other.GetName() == "Player")
		{
			Player &p = (Player &)other;
			if (this->IsCrashed()) //2nd collision
			{
				//Nothing happend in a second collision with a Side Object
				std::cout << "### Run over a " << this->GetName() << std::endl;
			}
			else //1st collision
			{
				std::cout << "### COLLISION -> Fire Hydrant" << std::endl;
				this->Crashed();
				this->SetName("water fountain");
				this->Fountain();
				p.ApplyDamage(this->GetDamage(), this->GetCash());
			} 
		}
		return;
	}

	//**************************************************************************************
	//
	void FireHydrant::Fountain()
	{
		std::cout << "WATER FOUNTAIN FROM THE FIRE HYDRANT!!" << std::endl;
	}
}