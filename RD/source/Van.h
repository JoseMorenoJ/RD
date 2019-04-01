#pragma once
/*
	class Van: behaviour of the traffic car type Van.
		Inherits from TrafficCar.
*/

#include "TrafficCar.h"

namespace RecklessDriver {

	class Van :
		public TrafficCar
	{
	public:
		Van();
		~Van();

		void OnCollision(const GameObject &other) override;
	};
}//namespace RecklesDriver
