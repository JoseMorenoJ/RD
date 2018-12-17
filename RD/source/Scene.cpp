/*
	class Scene: it holds all the objects that are active in the Screen.

*/

#include <iostream>
#include <thread>

#include "Scene.h"
#include "FireHydrant.h"
#include "LetterBox.h"
#include "Sedan.h"
#include "Van.h"
#include "Globals.h" // ORganization with the header declarations
#include "GameObject.h"

namespace RecklessDriver {

	//Constructor: starts the random generator
	Scene::Scene() : _engine(_rd()) {}

	//default Destructor
	Scene::~Scene(){}

	//Generates the scene view from the player.
	void Scene::Start(Player * pPlayer)
	{
		this->_pPlayer = pPlayer;
	}

	//Generate the objects in the scene.
	void Scene::GenerateNPCs()
	{
		//Check maximum side objects at a time (now 7)
		if (this->_sideObjects.size() > 6)
		{
			this->_sideObjects.erase(this->_sideObjects.begin()); //Erase the oldest item.
		}
		this->_sideObjects.push_back(GenerateSideObjects()); //TODO check if returns nullptr

		//Check maximum traffic cars at a time (now 5)
		if (this->_trafficObjects.size() > 4)
		{
			this->_trafficObjects.erase(this->_trafficObjects.begin()); //Erase the oldest item.
		}
		this->_trafficObjects.push_back(GenerateTraffic()); //		same
		
		//Show in screen the objects:
		DisplaySideObjects();
		DisplayTraffic();
	}

	void Scene::Collide()
	{
		//TODO: fix the random generators.
		std::uniform_int_distribution<int> dist(0, std::max(Globals::N_SIDEOBJECT_TYPES, Globals::N_TRAFFIC_TYPES)-1);
		std::uniform_int_distribution<int> distSideObjects(0, this->_sideObjects.size()-1);
		std::uniform_int_distribution<int> distTrafficObjects(0, this->_trafficObjects.size()-1);

		//initialize the next game object in the pool
		GameObject *pGO = nullptr;
		//Switch between side object and traffic car
		switch (dist(this->_engine))
		{
		case 0: //SideObject
			pGO = _sideObjects[distSideObjects(this->_engine)];
			break;
		case 1: //Traffic
			pGO = _sideObjects[distTrafficObjects(this->_engine)];
			break;
		default:
			break;
		}
		if (pGO != nullptr)
		{
			pGO->OnCollision(*this->_pPlayer);
			//Wait for 500 ms
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}

	//Add the different Side Objects to the objects pool.
	SideObject * Scene::GenerateSideObjects()
	{
		std::uniform_int_distribution<int> dist(0, Globals::N_SIDEOBJECT_TYPES-1);
		switch (dist(this->_engine))
		{
		case 0://Firehydrant
			return new FireHydrant(Globals::FIREHYDRANT_DAMAGE, Globals::FIREHYDRANT_CASH);
			break;
		case 1: //LetterBox
			return new LetterBox(Globals::LETTERBOX_DAMAGE, Globals::LETTERBOX_CASH);
			break;
		default:
			break;
		}
		return nullptr;
	}

	//Add the different Traffic to the objects pool.
	TrafficCar * Scene::GenerateTraffic()
	{
		std::uniform_int_distribution<int> dist(0, Globals::N_TRAFFIC_TYPES-1);
		switch (dist(this->_engine))
		{
		case 0://Sedan
			return new Sedan(Globals::SEDAN_DAMAGE, Globals::SEDAN_CASH);
			break;
		case 1: //Van
			return new Van(Globals::VAN_DAMAGE, Globals::VAN_CASH);
			break;
		default:
			break;
		}
		return nullptr;
	}

	//
	void Scene::DisplaySideObjects()
	{
		std::cout << "\nSide OBJECTS" << std::endl;
		for (const auto *p : this->_sideObjects)
		{
			std::cout << p->GetName() << "\t";
		}
		std::cout << std::endl;
	}

	void Scene::DisplayTraffic()
	{
		std::cout << "\nTraffic OBJECTS" << std::endl;
		for (const auto *p : this->_trafficObjects)
		{
			std::cout << p->GetName() << "\t";
		}
		std::cout << std::endl;
	}

}//namespace RecklessDriver
