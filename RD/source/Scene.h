#pragma once
/*
	class Scene: it holds all the objects that are active in the Screen.
			and manages the possible crashes.

*/

#include <vector>
#include <random>

#include "Player.h"
#include "ObjectPool.h"

namespace RecklessDriver {

	class Scene
	{
	public:
		Scene(ObjectPool &pool, Player &player);
		~Scene();

		void Collide();

	private:
		//Necessary for a random collision generation
		std::random_device _rd;
		std::default_random_engine _engine;

		ObjectPool _pool; //pool of game objects
		Player _player; //Player Car

	};

}//namespace RecklessDriver
