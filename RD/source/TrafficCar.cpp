/*
	class TrafficCar: behaviour of the traffic cars in the game, not controlled by the player.
		Inherits from GameObject.
*/
#include <iostream>


#include "TrafficCar.h"
	
//**************************************************************************************
//Constructor
TrafficCar::TrafficCar(int damage, int cash)
	:_damage(damage)
	, _cash(cash)
	,_bCrashed(false)
{
	SetName("");
	SetTag("Traffic Car");
}

//**************************************************************************************
//default Destructor
TrafficCar::~TrafficCar() {}

//**************************************************************************************
//Setters
void TrafficCar::SetDamage(int newDamage) { this->_damage = newDamage; }
void TrafficCar::SetCash(int newCash) { this->_cash = newCash; }
void TrafficCar::Crashed() { this->_bCrashed = true; }

//**************************************************************************************
//Getters
int TrafficCar::GetDamage() const { return this->_damage; }
int TrafficCar::GetCash() const { return this->_cash; }
bool TrafficCar::IsCrashed() const { return this->_bCrashed; }

//**************************************************************************************
//Called after a collision.
void TrafficCar::Sparks()
{
	std::cout << "SPARKS COMING OUT FROM " << this->GetName() << "!!" << std::endl;
}
