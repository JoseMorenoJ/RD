#pragma once
/*
	class TrafficCar: behaviour of the traffic cars in the game, not controlled by the player.
		Inherits from GameObject.
*/

#include "GameObject.h"

class TrafficCar :
	public GameObject
{
public:
	TrafficCar(int damage, int cash);
	~TrafficCar(); 
		
	void setDamage(int);
	void setCash(int);

	int getDamage() const;
	int getCash() const;
    
    void update() override;
	
protected:
	void sparks();

private:
	int _damage;   //the damage to the player car
	int _cash;	   //cash given after crash
    
};
