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
	setName("Player");
	setTag("Player");
    setX(2);
    setY(0);
}
Player::Player(PlayerVehicle &vehicle)
	: _health(params::PLAYER_INIT_HEALTH)
	, _vehicle(vehicle)
{
	setName("Player");
	setTag("Player");
    setChar('O');
}

//**************************************************************************************
//default Destructor
Player::~Player() {}
	
//**************************************************************************************
//getHealth:
int Player::getHealth() const { return _health; }

//**************************************************************************************
//Check on the players health.
bool Player::isAlive() const
{ 
	if(_health > 0)
		return true;
	else return false;
}

//**************************************************************************************
//Handling input
void Player::update()
{
    //Add a return type here, the event (key stroke)
    if (GameManager::getInstance().CLOCK() % params::SEDAN_HANDLING == 0) {
        _input.handleInput(this);
    }
}
//**************************************************************************************
//Mouvement for the player relates directly with the Player Vehicle mouvement functions.
void Player::accelerate() { _vehicle.up(); }
void Player::brake() { _vehicle.down(); }
void Player::steerRight() { _vehicle.right(); }
void Player::steerLeft() { _vehicle.left(); }

void Player::onCollision(const GameObject & other)
{
	// so it compiles
}

//**************************************************************************************
//Called when player collides with another object
void Player::applyDamage(int damage, int cash)
{
	_health -= damage - _vehicle.getStrength();
	GameManager::getInstance().addCash(cash);
}

