/*
	class SideObject: behaviour of all the objects in the side of the road.
		Inherits from GameObject.
*/

#include "SideObject.h"

//**************************************************************************************
//Constructor
SideObject::SideObject(int damage, int cash)
	:_damage(damage)
	, _cash(cash)
	, _bCrashed(false)
{
	setName("");
	setTag("Side Object");

}
	
//**************************************************************************************
//default Destructor
SideObject::~SideObject(){}

//**************************************************************************************
//Setters:
void SideObject::setDamage(int newDamage) { this->_damage = newDamage; }
void SideObject::setCash(int newCash) { this->_cash = newCash; }
void SideObject::crashed() { this->_bCrashed = true; }
	
//**************************************************************************************
//Getters:
int SideObject::getDamage() const { return this->_damage; }
int SideObject::getCash() const { return this->_cash; }
bool SideObject::isCrashed() const { return this->_bCrashed; }
