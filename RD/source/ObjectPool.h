#pragma once
/*
	class ObjectPool: pool for all the GameObjects used by the Scene.
		It will be limited to 10 objects in total.
*/

#include <vector>
#include <random>

#include "GameObject.h"

namespace RecklessDriver {

	class ObjectPool
	{
	public:
		ObjectPool();
		ObjectPool(const ObjectPool &pool);
		~ObjectPool();

		std::vector<GameObject *> &GetvGameObjects(); //cannot be const cause it returns &value

		void GenerateNewPoolObject();

	private:
		//Necessary for a random object generation
		std::random_device _rd;					 //random device
		std::default_random_engine _engine;		 //random engine
		std::vector<GameObject *> _vGameObjects; //list of Game Objects created

		//Some helper functions
		GameObject * GenerateNextObject();

	};

}//namespace RecklessDriver
