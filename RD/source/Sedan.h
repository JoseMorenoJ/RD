#pragma once
/*
	class Sedan: behaviour of the traffic car type Sedan.
		Inherits from TrafficCar.
*/

#include "TrafficCar.h"

class Sedan :
	public TrafficCar
{
public:
	Sedan();
	~Sedan();
    
    void update() override;
	void onCollision(const GameObject &other) override;
};
