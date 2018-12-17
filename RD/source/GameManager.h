#pragma once
/*
	class GameManager: takes charge of the game objects. Keeps track of the
		game process.
*/

#include "Player.h"

namespace RecklessDriver {
	class GameManager
	{
	public:
		~GameManager();

		int GetCash() const;
		static GameManager & GetInstance();

		void AddCash(int);
		
		void NewGame();
		void EndGame();

		void ShowStats(Player * pPlayer);

	private:
		int _cash; //Total cash accumulated

		void Drive();

		GameManager(); //We make it private so we cannot call GetInstance from out the class.


	};
}
