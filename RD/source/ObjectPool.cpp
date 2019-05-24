/*
	class ObjectPool: pool for all the GameObjects used by the Scene.
		It will be limited to 10 objects in total.
*/

#include <iostream>
#include <thread>

#include "ObjectPool.h"
#include "GameObject.h"
#include "FireHydrant.h"
#include "LetterBox.h"
#include "Sedan.h"
#include "Van.h"
#include "params.h"

//**************************************************************************************
//Constructor
ObjectPool::ObjectPool() : _engine(_rd())
{
	//Initialise the pool with 10 nullptrs
	_vGameObjects = std::vector<GameObject *>(params::POOL_SIZE, nullptr);
}
//Copy constructor
ObjectPool::ObjectPool(const ObjectPool &pool) : _engine(_rd())
{
	_vGameObjects = pool._vGameObjects;
}

//**************************************************************************************
//default Destructor 
ObjectPool::~ObjectPool(){}

//**************************************************************************************
//Getters
std::vector<GameObject*> & ObjectPool::GetvGameObjects() { return _vGameObjects; }

//**************************************************************************************
//Generate the objects in the scene.
void ObjectPool::GenerateNewPoolObject()
{
	//Check maximum game objects at a time
	if (this->_vGameObjects.size() >= params::POOL_SIZE)
	{
		if (this->_vGameObjects[0] != nullptr)
		{
			//Free the object from the heap
			delete this->_vGameObjects[0];
		}
		this->_vGameObjects.erase(this->_vGameObjects.begin()); //Erase the pointer to the oldest item.
	}
	//Push back the next object.
	this->_vGameObjects.push_back( this->GenerateNextObject() );

}

//**************************************************************************************
//TODO: check what is the factory pattern and if we can use it here
//Add the different Side Objects to the objects pool.
GameObject * ObjectPool::GenerateNextObject()
{
	//Define const variables:
	const int SWITCH_CASES = 5;

	//Generate the objects depending on the uniform distribution
	std::uniform_int_distribution<int> dist(0, SWITCH_CASES - 1);
	switch (dist(this->_engine))
	{
	case 0://NO INIT Object, nothing happens with it.
		return nullptr;
	case 1://FireHydrant
		return new FireHydrant();
	case 2: //LetterBox
		return new LetterBox();
	case 3://Sedan
		return new Sedan();
	case 4: //Van
		return new Van();
	default: //Just in case we get out of the range.
		return nullptr;
	}
}
