#pragma once
/*
	class Hub: it displays the game information after every iteration.
		
*/

#include <vector>
#include <random>

#include "ObjectPool.h"
#include "Player.h"


namespace RecklessDriver {

	class Hub
	{
	public:
		Hub();
		~Hub();

		void update(ObjectPool *, Player *);

	private:

		//Some Helper functions
		void DisplaySideObjects(ObjectPool *);
		void DisplayTraffic(ObjectPool *);

	};

}//namespace RecklessDriver
