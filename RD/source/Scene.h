#pragma once
/*
	class Scene: it holds all the objects that are active in the Screen.

*/

#include <vector>
#include <random>

//#include "Globals.h"
#include "SideObject.h"
#include "TrafficCar.h"
#include "Player.h"

namespace RecklessDriver {

	class Scene
	{
	public:
		Scene();
		~Scene();

		void Start(Player *pPlayer);
		void GenerateNPCs();
		void Collide();

	private:
		std::vector<SideObject *> _sideObjects;		//list of sideobjects created
		std::vector<TrafficCar *> _trafficObjects;  //list of traffic cars created
		Player *_pPlayer;

		//Necessary for a random object generation
		std::random_device _rd;
		std::default_random_engine _engine;

		//Some Helper functions
		SideObject* GenerateSideObjects();
		TrafficCar* GenerateTraffic();
		void DisplaySideObjects();
		void DisplayTraffic();
	};

}//namespace RecklessDriver
