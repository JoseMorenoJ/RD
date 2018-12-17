#pragma once
/*
	class SideObject: behaviour of all the objects in the side of the road.
		Inherits from GameObject.
*/

#include "GameObject.h"

namespace RecklessDriver {

	class SideObject :
		public GameObject
	{
	public:
		SideObject(int damage, int cash);
		~SideObject();

		void SetDamage(int);
		void SetCash(int);
		void SetCount(int);

		int GetDamage() const;
		int GetCash() const;
		int GetCount() const;

	protected:
		int _count;  //count of consecutive crashes with the side object

	private:
		int _damage; //damage done to the players car
		int _cash;	//cash given to the player after the first crash

	};
}//namespace RecklessDriver
