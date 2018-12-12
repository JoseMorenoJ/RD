#include "TrafficCar.h"


namespace RecklessDriver {
	
	//Constructor
	TrafficCar::TrafficCar(int damage, int cash)
		:damage(this->damage)
		, cash(this->cash)
	{}

	TrafficCar::~TrafficCar() {}

	//Getters
	int TrafficCar::GetDamage() { return this->damage; }
	int TrafficCar::GetCash() { return this->cash; }

}//namespace RecklessDriver
