#pragma once
/*
	class SideObject: behaviour of all the objects in the side of the road.
		Inherits from GameObject.
*/

#include "GameObject.h"

class SideObject :
	public GameObject
{
public:
	SideObject(int damage, int cash);
	~SideObject();

	void setDamage(int);
	void setCash(int);

	int getDamage() const;
	int getCash() const;

private:
	int _damage; //damage done to the players car
	int _cash;	//cash given to the player after the first crash
};
