#pragma once
/*
	class GameManager: takes charge of the game objects. Keeps track of the
		game process.
*/

namespace RecklessDriver {
	class GameManager
	{
	public:
		GameManager();
		~GameManager();

		int GetCash() const;

		void AddCash(int);
		
		void NewGame();
		void EndGame();

	private:
		int _cash; //Total cash accumulated

	};
}
