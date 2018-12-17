#pragma once
/*
	class TrafficCar: behaviour of the traffic cars in the game, not controlled by the player.
		Inherits from GameObject.
*/

#include "GameObject.h"

namespace RecklessDriver {

	class TrafficCar :
		public GameObject
	{
	public:
		TrafficCar(int damage, int cash);
		~TrafficCar(); 
		
		int GetDamage() const;
		int GetCash() const;
	
	protected:
		void Sparks();
	
	private:
		int _damage; //the damage to the player car
		int _cash;	 //cash given after crash
		
	};

} //namespace RecklessDriver