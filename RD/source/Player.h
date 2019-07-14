#pragma once
/*
	class Player: class representing the player.
		Inherits from GameObject.
*/

#include "GameObject.h"
#include "PlayerVehicle.h"
#include "InputHandler.h"

class Player :
	public GameObject
{
public:
	Player();
	Player(PlayerVehicle &vehicle);
	~Player();

	int GetHealth() const;
	bool IsAlive() const;

	void Accelerate();
	void Brake();
	void SteerRight();
	void SteerLeft();

	void OnCollision(const GameObject &other);
	void ApplyDamage(int damage, int cash);

private:
	PlayerVehicle _vehicle; //pointer to the player's vehicle
	int _health; //represents the health of the player
    InputHandler _input;
};
