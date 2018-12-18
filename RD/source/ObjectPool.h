#pragma once
/*
	class ObjectPool: pool for all the GameObjects used by the Scene.
		It will be limited to 10 objects in total.
*/

#include <vector>
#include <random>

#include "SideObject.h"
#include "TrafficCar.h"

namespace RecklessDriver {

	class ObjectPool
	{
	public:
		ObjectPool();
		~ObjectPool();

		std::vector<SideObject *> *GetvSideObjects();
		std::vector<TrafficCar *> *GetvTraffic();

		void GenerateNPCs();

	private:
		//Necessary for a random object generation
		std::random_device _rd;
		std::default_random_engine _engine;

		std::vector<SideObject *> _vSideObjects;		//list of sideobjects created
		std::vector<TrafficCar *> _vTrafficObjects;  //list of traffic cars created

		//Some helper functions
		SideObject* GenerateSideObjects();
		TrafficCar* GenerateTraffic();
	};

}//namespace RecklessDriver
