/*
	class Scene: it holds all the objects that are active in the Screen
			and manages the possible crashes.

*/

#include <iostream>
#include <random>

#include "Scene.h"

//**************************************************************************************
//Constructor: starts the random generator
Scene::Scene(ObjectPool &pool, Player &player)
	: _pool(pool)
	, _player(player)
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
	std::uniform_int_distribution<int> dist(0, _pool.GetvGameObjects().size()-1);
		
	GameObject *pGO = nullptr;
	//Select a random object to colide
	pGO = (_pool.GetvGameObjects()) [dist(_engine)];

	if (pGO != nullptr)
	{
		pGO->OnCollision(_player);
		system("pause");
	}
}
