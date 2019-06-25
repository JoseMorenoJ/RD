#pragma once
/*
	class GameManager: takes charge of the game objects. Keeps track of the
		game process.
*/

#include "Player.h"

class GameManager
{
public:
	~GameManager();

	int GetCash() const;
	static GameManager & GetInstance();

	void AddCash(int);
		
	void NewGame();
	void EndGame();
	bool PlayAgain();

private:
	int _cashAccum;	//Total cash accumulated

	GameManager();  //We make it private so we cannot call GetInstance from out the class.
		
	//Helper methods
	void ResetCash(); 

};
