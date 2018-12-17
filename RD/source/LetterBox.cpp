/*
	class LetterBox: behaviour of the side object of the type letter box.
		Inherits from SideObject.
*/

#include <iostream>

#include "LetterBox.h"
#include "Player.h"

namespace RecklessDriver {

	//Constructor
	LetterBox::LetterBox(int damage, int cash) : SideObject(damage, cash) 
	{
		SetName("Letter Box");
	}

	//default Destructor
	LetterBox::~LetterBox(){}

	//Specifies the behaviour when two GameObject collide
	void LetterBox::OnCollision(const GameObject & other)
	{
		if (other.GetName() == "Player")
		{
			Player &p = (Player &)other;
			if (_count == 0)
			{
				std::cout << "### COLLISION -> Letter Box" << std::endl;
				this->LettersFlying();
				p.ApplyDamage(this->GetDamage(), this->GetCash());
			}
			else
			{
				std::cout << "### EXTRA COLLISION -> Letter Box" << std::endl;
				p.ApplyDamage(this->GetDamage(), this->GetCash());
			}
		}
		return;
	}

	//show on collision
	void LetterBox::LettersFlying()
	{
		std::cout << "LETTERS FLYING FROM THE LETTER BOX!!" << std::endl;
	}
}
