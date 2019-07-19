#pragma once
/*
	class Hub: it displays the game information after every iteration.
		
*/

#include <vector>
#include <random>

#include "ObjectPool.h"
#include "Player.h"
#include "params.h"

class Hub
{
public:
	Hub();
	~Hub();

	void refresh(ObjectPool &pool, Player &player);
	void driving() const;
	void showEndGame(int) const;

private:
    char _display[params::SCREEN_HOR][params::SCREEN_VER];
    
	//Some Helper functions
	void displayGameObjects(ObjectPool &, Player &);
	void showStats(const Player &player);
    void resetDisplay();

};
