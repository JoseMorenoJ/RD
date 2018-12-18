/*
	class Scene: it holds all the objects that are active in the Screen.

*/

#include <iostream>
#include <thread>
#include <random>

#include "Scene.h"


namespace RecklessDriver {

	//Constructor: starts the random generator
	Scene::Scene(ObjectPool* pPool, Player* pPlayer)
		: _pPool(pPool)
		, _pPlayer(pPlayer)
		, _engine(_rd())
	{}

	//default Destructor
	Scene::~Scene(){}

	//Generates the scene view from the player.
	void Scene::Start(Player * pPlayer)
	{
		this->_pPlayer = pPlayer;
	}


	void Scene::Collide()
	{
		//TODO: fix the random generators.
		std::uniform_int_distribution<int> dist(0, 1);
		std::uniform_int_distribution<int> distSideObjects(0, this->_pPool->GetvSideObjects()->size()-1);
		std::uniform_int_distribution<int> distTrafficObjects(0, this->_pPool->GetvTraffic()->size()-1);

		//initialize the next game object in the pool
		GameObject *pGO = nullptr;
		//Switch between side object and traffic car
		switch (dist(this->_engine))
		{
		case 0: //Get a random element from the vector of side objects from the pool.
			pGO = (*this->_pPool->GetvSideObjects()) [distSideObjects(this->_engine)];
			break;
		case 1: //Get a random element from the vector of traffic objects from the pool.
			pGO = (*this->_pPool->GetvTraffic()) [distTrafficObjects(this->_engine)];
			break;
		default:
			break;
		}
		if (pGO != nullptr)
		{
			pGO->OnCollision(*this->_pPlayer);
			//Wait for 500 ms
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}

}//namespace RecklessDriver
