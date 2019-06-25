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

	void SetName(std::string);
	void SetHandling(int);
	void SetTopSpeed(int);
	void SetStrength(int);

	std::string GetName() const;
	int GetHandling() const;
	int GetTopSpeed() const;
	int GetStrength() const;

	void Up();
	void Down();
	void Left();
	void Right();

private:
	std::string _name; //unique name identifier
	int _handling;	   //how fast it turns to the sides
	int _topSpeed;	   //maximun speed reachable
	int _strength;	   //robustenss of the vehicle
};