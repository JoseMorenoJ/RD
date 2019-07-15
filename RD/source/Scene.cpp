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
void Scene::Collide()
{
	//Generate a random distribution object for the collision.
	std::uniform_int_distribution<int> dist(0, _pPool->GetvGameObjects().size()-1);
		
	GameObject *pGO = nullptr;
	//Select a random object to colide
	pGO = (_pPool->GetvGameObjects()) [dist(_engine)];

	if (pGO != nullptr)
	{
		pGO->OnCollision(*_pPlayer);
	}
}

//**************************************************************************************
//Generate and return a random number between the number of game object types
int const Scene::GetRand()
{
    //Generate a random distribution object for the collision.
    std::uniform_int_distribution<int> dist(0, params::N_TOTAL_TYPES -1);
    return dist(_engine);
}

//**************************************************************************************
//Generate and return a random number between the number of game object types
void Scene::AddObject()
{
    _pPool->GenerateNextObject(GetRand());
}
