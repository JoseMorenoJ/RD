#pragma once
/*
	class Scene: it holds all the objects that are active in the Screen.

*/

#include <vector>
#include <random>

#include "Player.h"
#include "ObjectPool.h"

namespace RecklessDriver {

	class Scene
	{
	public:
		Scene(ObjectPool*, Player*);
		~Scene();

		void Start(Player *pPlayer);
		void Collide();

	private:
		//Necessary for a random collision generation
		std::random_device _rd;
		std::default_random_engine _engine;

		ObjectPool *_pPool; //pool of game objects
		Player *_pPlayer; //Player Car

	};

}//namespace RecklessDriver
