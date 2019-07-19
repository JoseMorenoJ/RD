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
    //aRand is 0, dont do anything.
    if (aRand == 0) return;
	
    //Choose the type depending on the aRand obtained.
    EGameObject nextObj = EGameObject::NO_INIT;
    for (int i=0; i < aRand; i++)
    {
        nextGO(nextObj);
    }
    
    bool objectFound = false;
    //Look for a non active GObject of that type in the pool
    for (auto &e: _vGameObjects)
    {
        if (e->getType() == nextObj && !e->isActive())
        {
            //Activate it and initialise its position
            e->activate();
            e->setY(params::SCREEN_VER);
            if(e->getTag() == "Traffic Car")
                e->setX(2); //Start the traffic cars inside the road
            if(e->getTag() == "Side Object")
                e->setX(0); //Side object in the sides
            objectFound = true;
            break; //stop iterating
        }
    }
    if (!objectFound)
    {
        _vGameObjects.push_back(newObject(nextObj));
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

GameObject* ObjectPool::newObject(const EGameObject& type)
{
    //allocate a new object depending on the EGameObject type
    switch (type) {
        case EGameObject::FIRE_HYDRANT:
            return new FireHydrant();
        case EGameObject::LETTER_BOX:
            return new LetterBox();
        case EGameObject::SEDAN:
            return new Sedan();
        case EGameObject::VAN:
            return new Van();
        default: //it should never arrive to this point
            return nullptr;
    }
}
