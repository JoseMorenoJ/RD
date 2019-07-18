/*
	class LetterBox: behaviour of the side object of the type letter box.
		Inherits from SideObject.
*/

#include <iostream>

#include "LetterBox.h"
#include "Player.h"
#include "params.h"
#include "GameManager.h"

//**************************************************************************************
//Constructor
LetterBox::LetterBox() : SideObject(params::LETTERBOX_DAMAGE, params::LETTERBOX_CASH)
{
	setName("Letter Box");
    setChar('L');
}

//**************************************************************************************
//default Destructor
LetterBox::~LetterBox(){ std::cout << "~LetterBox()" << std::endl; }

void LetterBox::update()
{
    {
        if (GameManager::getInstance().CLOCK() % params::LETTERBOX_FREQ == 0)
        {
            if (getY() == 0)
            {
                this->reset();
            }
            else
            {
                setY(getY() - 1);
            }
        }
    }
}

//**************************************************************************************
//Specifies the behaviour when two GameObject collide.
void LetterBox::onCollision(const GameObject & other)
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
			std::cout << "### COLLISION -> Letter Box" << std::endl;
			this->_bCrashed = true;
			this->setName("letters flying");
			this->lettersFlying();
			p.applyDamage(this->getDamage(), this->getCash());
		}
	}
	return;
}

//**************************************************************************************
//Show on collision.
void LetterBox::lettersFlying()
{
	std::cout << "LETTERS FLYING FROM THE LETTER BOX!!" << std::endl;
}
