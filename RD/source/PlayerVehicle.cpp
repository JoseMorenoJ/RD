/*
	class PlayerVehicle: describes the vehicle controled by the player.

*/

#include <string>

#include "PlayerVehicle.h"
#include "params.h"
	
//**************************************************************************************
//Constructor
PlayerVehicle::PlayerVehicle()
{
	_name = "Sedan";
	_handling = params::SEDAN_HANDLING;
	_topSpeed = params::SEDAN_TOPSPEED;
	_strength = params::SEDAN_STRENGTH;
}
//Copy Constructor
PlayerVehicle::PlayerVehicle(const PlayerVehicle &vehicle)
{
	_name = vehicle._name;
	_handling = vehicle._handling;
	_topSpeed = vehicle._topSpeed;
	_strength = vehicle._strength;
}
//**************************************************************************************

//**************************************************************************************
//default Destructor
PlayerVehicle::~PlayerVehicle(){}

//**************************************************************************************
//Setters:
void PlayerVehicle::SetName(std::string newName) { this->_name = newName; }
void PlayerVehicle::SetHandling(int newHandling) { this->_handling = newHandling; }
void PlayerVehicle::SetTopSpeed(int newTopSpeed) { this->_topSpeed = newTopSpeed; }
void PlayerVehicle::SetStrength(int newStrength) { this->_strength = newStrength; }
	
//**************************************************************************************
//Getters:
std::string PlayerVehicle::GetName() const { return this->_name; }
int PlayerVehicle::GetHandling() const { return this->_handling; }
int PlayerVehicle::GetTopSpeed() const { return this->_topSpeed; }
int PlayerVehicle::GetStrength() const { return this->_strength; }

//**************************************************************************************
//Increases the speed of the player's car
void PlayerVehicle::Up()
{
	return; //TODO implement Up() when using the graphics
}
	
//**************************************************************************************
//Slows down or moves backwards the player's car
void PlayerVehicle::Down()
{
	return; //TODO implement Down() when using the graphics
}

//**************************************************************************************
//Steer left the player's car
void PlayerVehicle::Left()
{
	return; //TODO implement Left() when using the graphics
}

//**************************************************************************************
//Steer's right the player's car
void PlayerVehicle::Right()
{
	return; //TODO implement Right() when using the graphics
}
