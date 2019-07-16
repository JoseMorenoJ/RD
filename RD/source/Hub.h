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

	void update(ObjectPool &pool, Player &player);
	void driving() const;
	void showEndGame(int) const;

private:

	//Some Helper functions
	void displayGameObjects(ObjectPool &pool);
	void showStats(const Player &player);

};
