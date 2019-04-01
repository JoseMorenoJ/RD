/*
	class SideObject: behaviour of all the objects in the side of the road.
		Inherits from GameObject.
*/

#include "SideObject.h"

namespace RecklessDriver {
	
	//**************************************************************************************
	//Constructor
	SideObject::SideObject(int damage, int cash)
		:_damage(damage)
		, _cash(cash)
		, _bCrashed(false)
	{
		SetName("");
		SetTag("Side Object");

	}
	
	//**************************************************************************************
	//default Destructor
	SideObject::~SideObject(){}

	//**************************************************************************************
	//Setters:
	void SideObject::SetDamage(int newDamage) { this->_damage = newDamage; }
	void SideObject::SetCash(int newCash) { this->_cash = newCash; }
	void SideObject::Crashed() { this->_bCrashed = true; }
	
	//**************************************************************************************
	//Getters:
	int SideObject::GetDamage() const { return this->_damage; }
	int SideObject::GetCash() const { return this->_cash; }
	bool SideObject::IsCrashed() const { return this->_bCrashed; }

}//namespace RecklessDriver
