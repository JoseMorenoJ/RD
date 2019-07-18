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
ObjectPool::ObjectPool()
{
    _vGameObjects.push_back(new Sedan);
    _vGameObjects.push_back(new Sedan);
    _vGameObjects.push_back(new Sedan);
    _vGameObjects.push_back(new Sedan);
    _vGameObjects.push_back(new Van);
    _vGameObjects.push_back(new Van);
    _vGameObjects.push_back(new LetterBox);
    _vGameObjects.push_back(new LetterBox);
    _vGameObjects.push_back(new FireHydrant);
    _vGameObjects.push_back(new FireHydrant);
}

//**************************************************************************************
//default Destructor 
ObjectPool::~ObjectPool(){}

//**************************************************************************************
//getters
std::vector<GameObject*> & ObjectPool::getvGameObjects() { return _vGameObjects; }

//**************************************************************************************
//Generate the objects in the scene.
void ObjectPool::generateNextObject(const int aRand)
{
	//Choose the type depending on the aRand obtained.
    EGameObject obj = EGameObject::NO_INIT;
    for (int i=0; i < aRand; i++)
    {
        ++obj;
    }
    
    //Look for a non active GObject of that type in the pool
    for (auto const e: _vGameObjects)
    {
        if (e->getType() == obj && !e->isActive())
        {
            //Activate it and initialise its position
            e->activate();
            e->setY(params::SCREEN_VER);
            if(e->getType() == SEDAN || e->getType() == VAN)
                e->setX(2); //Start the traffic cars inside the road
            if(e->getType() == LETTER_BOX || e->getType() == FIRE_HYDRANT)
                e->setY(0); //Side object in the sides
            break; //stop iterating
        }
    }
}

void ObjectPool::updateObjects()
{
    for(auto obj: _vGameObjects)
    {
        if (obj->isActive())
        {
            obj->update();
        }
    }
}