/*
	class Player: class representing the player.
		Inherits from GameObject.
*/

#include "Player.h"
#include "GameManager.h"
#include "params.h"

//**************************************************************************************
//Constructor
Player::Player() 
	: _health(params::PLAYER_INIT_HEALTH)
{
	_vehicle = PlayerVehicle();
	SetName("Player");
	SetTag("Player");
}
Player::Player(PlayerVehicle &vehicle)
	: _health(params::PLAYER_INIT_HEALTH)
	, _vehicle(vehicle)
{
	SetName("Player");
	SetTag("Player");
}

//**************************************************************************************
//default Destructor
Player::~Player() {}
	
//**************************************************************************************
//GetHealth:
int Player::GetHealth() const { return _health; }

//**************************************************************************************
//Check on the players health.
bool Player::IsAlive() const 
{ 
	if(_health > 0)
		return true;
	else return false;
}

//**************************************************************************************
//Mouvement for the player relates directly with the Player Vehicle mouvement functions.
void Player::Accelerate() { _vehicle.Up(); }
void Player::Brake() { _vehicle.Down(); }
void Player::SteerRight() { _vehicle.Right(); }
void Player::SteerLeft() { _vehicle.Left(); }

//**************************************************************************************
//Called when player collides with another object
void Player::ApplyDamage(int damage, int cash)
{
	_health -= damage - _vehicle.GetStrength();
	GameManager::GetInstance().AddCash(cash);
}

