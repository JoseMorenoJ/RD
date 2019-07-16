#pragma once
/*
	class ObjectPool: pool for all the GameObjects used by the Scene.
		It will be limited to 10 objects in total.
*/

#include <vector>
#include <random>

#include "GameObject.h"

class ObjectPool
{
public:
	ObjectPool();
	~ObjectPool();

	std::vector<GameObject *> &getvGameObjects(); //cannot be const cause it returns &value

    void generateNextObject(const int);
    
private:
    //TODO Make it a list of unique pointers
	std::vector<GameObject *> _vGameObjects; //list of Game Objects created

	//Some helper functions

};
