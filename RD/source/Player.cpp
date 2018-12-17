/*
	class Player: class representing the player.
		Inherits from GameObject.
*/

#include "Player.h"
#include "GameManager.h"

namespace RecklessDriver {

	//Constructor
	Player::Player(int health, PlayerVehicle * pVehicle)
		: _health(health)
		, _pVehicle(pVehicle)
	{
		this->SetName("Player");
	}

	//default Destructor
	Player::~Player()
	{
	}
	//GetHealth:
	int Player::GetHealth() { return this->_health; }

	//Check on the players health.
	bool Player::IsAlive() const 
	{ 
		if(this->_health > 0)
			return true;
		else return false;
	}

	//Mouvement for the player relates directly with the Player Vehicle mouvement functions.
	void Player::Accelerate() { this->_pVehicle->Up(); }
	void Player::Brake() { this->_pVehicle->Down(); }
	void Player::SteerRight() { this->_pVehicle->Right(); }
	void Player::SteerLeft() { this->_pVehicle->Left(); }

	//Called when player collides with another object
	void Player::ApplyDamage(int damage, int cash)
	{
		this->_health -= damage - this->_pVehicle->GetStrength();
		GameManager::GetInstance().AddCash(cash);
	}

}
