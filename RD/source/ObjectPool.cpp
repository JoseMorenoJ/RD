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
//Getters
std::vector<GameObject*> & ObjectPool::GetvGameObjects() { return _vGameObjects; }

//**************************************************************************************
//Generate the objects in the scene.
void ObjectPool::GenerateNextObject(const int aRand)
{
	//Choose the type depending on the aRand obtained.
    EGameObject obj;
    for (int i=0; i < aRand; i++)
    {
        ++obj;
    }
    
    //Look for a non active GObject of that type in the pool
    for (auto const e: _vGameObjects) {
        if (e->GetType() == obj && !e->isActive()) {
            //Activate it and initialise its position
        }
    }
    
    switch (aRand)
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

