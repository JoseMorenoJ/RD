#pragma once
/*
	class Player: class representing the player.
		Inherits from GameObject.
*/

#include "GameObject.h"
#include "PlayerVehicle.h"

namespace RecklessDriver {

	class Player :
		public GameObject
	{
	public:
		Player(int health, PlayerVehicle *pVehicle);
		~Player();

		bool IsAlive() const;

		void Accelerate();
		void Brake();
		void SteerRight();
		void SteerLeft();

		void ApplyDamage(int damage, int cash);

	private:
		PlayerVehicle *_pVehicle; //pointer to the player's vehicle
		int _health; //represents the health of the player
	};
}
