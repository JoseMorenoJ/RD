/*
	class LetterBox: behaviour of the side object of the type letter box.
		Inherits from SideObject.
*/

#include <iostream>

#include "LetterBox.h"
#include "Player.h"
#include "params.h"

namespace RecklessDriver {

	//**************************************************************************************
	//Constructor
	LetterBox::LetterBox() : SideObject(params::LETTERBOX_DAMAGE, params::LETTERBOX_CASH)
	{
		SetName("Letter Box");
	}

	//**************************************************************************************
	//default Destructor
	LetterBox::~LetterBox(){ std::cout << "~LetterBox()" << std::endl; }

	//**************************************************************************************
	//Specifies the behaviour when two GameObject collide.
	void LetterBox::OnCollision(const GameObject & other)
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
				std::cout << "### COLLISION -> Letter Box" << std::endl;
				this->Crashed();
				this->SetName("letters flying");
				this->LettersFlying();
				p.ApplyDamage(this->GetDamage(), this->GetCash());
				this->Crashed();
			}
		}
		return;
	}

	//**************************************************************************************
	//Show on collision.
	void LetterBox::LettersFlying()
	{
		std::cout << "LETTERS FLYING FROM THE LETTER BOX!!" << std::endl;
	}
}
