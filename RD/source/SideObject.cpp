/*
	class SideObject: behaviour of all the objects in the side of the road.
		Inherits from GameObject.
*/

#include "SideObject.h"

namespace RecklessDriver {
	
	//Constructor
	SideObject::SideObject(int damage, int cash)
		:_damage(damage)
		, _cash(cash)
		, _count(0)
	{
		SetName("Side Object");
	}
	
	//default Destructor
	SideObject::~SideObject(){}

	//Setters:
	void SideObject::SetDamage(int newDamage) { this->_damage = newDamage; }
	void SideObject::SetCash(int newCash) { this->_cash = newCash; }
	void SideObject::SetCount(int newCount) { this->_count = newCount; }
	//Getters:
	int SideObject::GetDamage() const { return this->_damage; }
	int SideObject::GetCash() const { return this->_cash; }
	int SideObject::GetCount() const { return this->_count; }

}//namespace RecklessDriver
