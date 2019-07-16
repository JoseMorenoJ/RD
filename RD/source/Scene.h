#pragma once
/*
	class Scene: it holds all the objects that are active in the Screen.
			and manages the possible crashes.

*/

#include <vector>
#include <random>

#include "Player.h"
#include "ObjectPool.h"
#include "GameObject.h"

class Scene
{
public:
	Scene(ObjectPool* pPool, Player* pPlayer);
	~Scene();

	void collide();
    int const getRand();
    void addObject();
    
private:
	//Necessary for a random collision generation
    //TODO Wrap it in the cool bind() thing (p.144)
	std::random_device _rd;
	std::default_random_engine _engine;

    ObjectPool* _pPool; //Object Pool
	Player* _pPlayer; //Player Car

};
