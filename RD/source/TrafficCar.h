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
		
		void SetDamage(int);
		void SetCash(int);
		void Crashed();

		int GetDamage() const;
		int GetCash() const;
		bool IsCrashed() const;
	
	protected:
		void Sparks();

	private:
		int _damage;   //the damage to the player car
		int _cash;	   //cash given after crash
		bool _bCrashed; //Wether is enabled or disabled
		
	};

} //namespace RecklessDriver