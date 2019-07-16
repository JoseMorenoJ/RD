/*
	class Scene: it holds all the objects that are active in the Screen
			and manages the possible crashes.

*/

#include <iostream>
#include <random>

#include "Scene.h"
#include "System.h"
#include "params.h"

//**************************************************************************************
//Constructor: starts the random generator
Scene::Scene(ObjectPool* pPool, Player* pPlayer)
	: _pPool(pPool)
	, _pPlayer(pPlayer)
	, _engine(_rd())
{}

//**************************************************************************************
//default Destructor
Scene::~Scene(){}

//**************************************************************************************
//Generate a collision between the player and one of the objects in the pool.
void Scene::collide()
{
	//Generate a random distribution object for the collision.
	std::uniform_int_distribution<int> dist(0, _pPool->getvGameObjects().size()-1);
		
	GameObject *pGO = nullptr;
	//Select a random object to colide
	pGO = (_pPool->getvGameObjects()) [dist(_engine)];

	if (pGO != nullptr)
	{
		pGO->onCollision(*_pPlayer);
	}
}

//**************************************************************************************
//Generate and return a random number between the number of game object types
int const Scene::getRand()
{
    //Generate a random distribution object for the collision.
    std::uniform_int_distribution<int> dist(0, params::N_TOTAL_TYPES -1);
    return dist(_engine);
}

//**************************************************************************************
//Generate and return a random number between the number of game object types
void Scene::addObject()
{
    _pPool->generateNextObject(getRand());
}
