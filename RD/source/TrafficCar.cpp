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
	setName("");
	setTag("Traffic Car");
}

//**************************************************************************************
//default Destructor
TrafficCar::~TrafficCar() {}

//**************************************************************************************
//setters
void TrafficCar::setDamage(int newDamage) { this->_damage = newDamage; }
void TrafficCar::setCash(int newCash) { this->_cash = newCash; }
void TrafficCar::crashed() { this->_bCrashed = true; }

//**************************************************************************************
//getters
int TrafficCar::getDamage() const { return this->_damage; }
int TrafficCar::getCash() const { return this->_cash; }
bool TrafficCar::isCrashed() const { return this->_bCrashed; }

//**************************************************************************************
//Called after a collision.
void TrafficCar::sparks()
{
	std::cout << "SPARKS COMING OUT FROM " << this->getName() << "!!" << std::endl;
}
