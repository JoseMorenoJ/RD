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

	int getHealth() const;
	bool isAlive() const;

    void update();
	void accelerate();
	void brake();
	void steerRight();
	void steerLeft();

	void onCollision(const GameObject &other);
	void applyDamage(int damage, int cash);

private:
	PlayerVehicle _vehicle; //pointer to the player's vehicle
	int _health; //represents the health of the player
    InputHandler _input;
};
