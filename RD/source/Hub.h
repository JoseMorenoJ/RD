#pragma once
/*
	class Hub: it displays the game information after every iteration.
		
*/

#include <vector>
#include <random>

#include "ObjectPool.h"
#include "Player.h"

class Hub
{
public:
	Hub();
	~Hub();

	void Update(ObjectPool* pPool, Player &player);
	void Driving() const;
	void ShowEndGame(int) const;

private:

	//Some Helper functions
	void DisplayGameObjects(ObjectPool* pPool);
	void ShowStats(const Player &player);

};
