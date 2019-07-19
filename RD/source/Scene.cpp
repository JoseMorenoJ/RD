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
//Generate and return a random number between the number of game object types
int const Scene::getRand()
{
    //Generate a random distribution object for the collision.
    std::uniform_int_distribution<int> dist(1, 10);
    return dist(_engine);
}

//**************************************************************************************
//Generate and return a random number between the number of game object types
void Scene::addObject()
{
    _pPool->generateNextObject(getRand());
}
