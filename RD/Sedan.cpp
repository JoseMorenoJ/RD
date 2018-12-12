#include "Sedan.h"

namespace RecklessDriver {

	//This initializes the values with the constructor from TrafficCar
	Sedan::Sedan(int damage, int cash):TrafficCar(damage, cash) {}

	Sedan::~Sedan(){}

	void Sedan::OnCollision(const GameObject & other)
	{
		return;
	}

}//namespace RecklessDriver
