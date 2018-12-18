/*
	class ObjectPool: pool for all the GameObjects used by the Scene.
		It will be limited to 10 objects in total.
*/

#include <iostream>
#include <thread>

#include "ObjectPool.h"
#include "FireHydrant.h"
#include "LetterBox.h"
#include "Van.h"
#include "Sedan.h"

namespace RecklessDriver {

	//Constructor
	ObjectPool::ObjectPool() : _engine(_rd()) {}

	//default Destructor
	ObjectPool::~ObjectPool(){}

	//Getters
	std::vector<SideObject*> * ObjectPool::GetvSideObjects() { return & this->_vSideObjects; }
	std::vector<TrafficCar*> * ObjectPool::GetvTraffic() { return & this->_vTrafficObjects; }

	//Generate the objects in the scene.
	void ObjectPool::GenerateNPCs()
	{
		//Check maximum side objects at a time (now 7)
		if (this->_vSideObjects.size() > 6)
		{
			this->_vSideObjects.erase(this->_vSideObjects.begin()); //Erase the oldest item.
		}
		this->_vSideObjects.push_back(GenerateSideObjects()); //TODO check if returns nullptr

		//Check maximum traffic cars at a time (now 5)
		if (this->_vTrafficObjects.size() > 4)
		{
			this->_vTrafficObjects.erase(this->_vTrafficObjects.begin()); //Erase the oldest item.
		}
		this->_vTrafficObjects.push_back(GenerateTraffic()); //		same

	}

	//Add the different Side Objects to the objects pool.
	SideObject * ObjectPool::GenerateSideObjects()
	{
		//Define const variables:
		const int N_SIDEOBJECT_TYPES = 2; //Fire Hydrant, Letter Box
		const int FIREHYDRANT_DAMAGE = 10;
		const int FIREHYDRANT_CASH = 10;
		const int LETTERBOX_DAMAGE = 11;
		const int LETTERBOX_CASH = 13;

		//Generate the objects depending on the uniform distribution
		std::uniform_int_distribution<int> dist(0, N_SIDEOBJECT_TYPES - 1);
		switch (dist(this->_engine))
		{
		case 0://Firehydrant
			return new FireHydrant(FIREHYDRANT_DAMAGE, FIREHYDRANT_CASH);
			break;
		case 1: //LetterBox
			return new LetterBox(LETTERBOX_DAMAGE, LETTERBOX_CASH);
			break;
		default:
			break;
		}
		return nullptr;
	}

	//Add the different Traffic to the objects pool.
	TrafficCar * ObjectPool::GenerateTraffic()
	{
		//Define const variables:
		const int N_TRAFFIC_TYPES = 2; //Sedan, Van
		const int SEDAN_DAMAGE = 10;
		const int SEDAN_CASH = 20;
		const int VAN_DAMAGE = 15;
		const int VAN_CASH = 25;

		//Generate the objects depending on the uniform distribution
		std::uniform_int_distribution<int> dist(0, N_TRAFFIC_TYPES - 1);
		switch (dist(this->_engine))
		{
		case 0://Sedan
			return new Sedan(SEDAN_DAMAGE, SEDAN_CASH);
			break;
		case 1: //Van
			return new Van(VAN_DAMAGE, VAN_CASH);
			break;
		default:
			break;
		}
		return nullptr;
	}

}//namespace RecklessDriver
