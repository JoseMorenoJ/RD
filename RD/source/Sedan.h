#pragma once
/*
	class Sedan: behaviour of the traffic car type Sedan.
		Inherits from TrafficCar.
*/

#include "TrafficCar.h"

namespace RecklessDriver {

	class Sedan :
		public TrafficCar
	{
	public:
		Sedan(int damage, int cash);
		~Sedan();

		void OnCollision(const GameObject &other) override;
	};
}//namespace RecklesDriver
