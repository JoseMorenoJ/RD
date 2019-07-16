#pragma once
/*
	class PlayerVehicle: describes the vehicle controled by the player.
		
*/

#include <string>

class PlayerVehicle
{
public:
	PlayerVehicle();
	PlayerVehicle(const PlayerVehicle &vehicle);
	~PlayerVehicle();

	void setName(std::string);
	void setHandling(int);
	void setTopSpeed(int);
	void setStrength(int);

	std::string getName() const;
	int getHandling() const;
	int getTopSpeed() const;
	int getStrength() const;

	void up();
	void down();
	void left();
	void right();

private:
	std::string _name; //unique name identifier
	int _handling;	   //how fast it turns to the sides
	int _topSpeed;	   //maximun speed reachable
	int _strength;	   //robustenss of the vehicle
};
