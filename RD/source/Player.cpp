/*
	class Player: class representing the player.
		Inherits from GameObject.
*/

#include "Player.h"

namespace RecklessDriver {

	//Constructor
	Player::Player(int health, PlayerVehicle * pVehicle)
		: _health(health)
		, _pVehicle(pVehicle)
	{}

	//default Destructor
	Player::~Player()
	{
	}

	//Check on the players health.
	bool Player::IsAlive() const 
	{ 
		if(this->_health > 0)
			return true;
		else return false;
	}

	//Mouvement for the player relates directly with the Player Vehicle mouvement functions.
	void Player::Accelerate() { this->_pVehicle->Up; }
	void Player::Brake() { this->_pVehicle->Down; }
	void Player::SteerRight() { this->_pVehicle->Right; }
	void Player::SteerLeft() { this->_pVehicle->Left; }

	//Called when player collides with another object
	void Player::ApplyDamage(int damage, int cash)
	{
		this->_health -= damage - this->_pVehicle->GetStrength();
	}

}
