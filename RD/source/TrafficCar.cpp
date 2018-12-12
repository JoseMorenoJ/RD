/*
	class TrafficCar: behaviour of the traffic cars in the game, not controlled by the player.
		Inherits from GameObject.
*/

#include "TrafficCar.h"

namespace RecklessDriver {
	
	//Constructor
	TrafficCar::TrafficCar(int damage, int cash)
		:_damage(damage)
		, _cash(cash)
	{}

	//default Destructor
	TrafficCar::~TrafficCar() {}

	//Getters
	int TrafficCar::GetDamage() const { return this->_damage; }
	int TrafficCar::GetCash() const { return this->_cash; }

}//namespace RecklessDriver
