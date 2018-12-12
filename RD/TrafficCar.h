#pragma once

#include "GameObject.h"

namespace RecklessDriver {

	class TrafficCar :
		public GameObject
	{
	public:
		TrafficCar(int damage, int cash);
		~TrafficCar(); 
		
		int GetDamage();
		int GetCash();
	private:
		int damage; //the damage to the player car
		int cash;	 //cash given after crash
		
	};

} //namespace RecklessDriver