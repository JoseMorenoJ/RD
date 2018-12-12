#pragma once
/*
	class GameObject: Base class for all the objects of the game.
		The game manager will interface with them.
*/

#include <string>

/* Why a namespace? 
	1. Prevent name clashes.
	2. Divide the application into manageable chunks.
	3. Searching/locating classes or other types.
	4. It DOESN'T encapsulate.
*/
namespace RecklessDriver {

	class GameObject
	{
	public:
		void SetName(std::string);
		void SetTag(std::string);
		void SetEnabled(bool);

		const std::string GetName() const;
		const std::string GetTag() const;
		bool IsEnabled() const;

		//not pure virtual: No, we don't want to implement OnCollision in objects that the player cannot crash with.
		virtual void OnCollision(const GameObject &other);

	private:
		std::string name; //To uniquely identify a game object
		std::string tag;  //To uniquely identify a group of objects
		bool enabled;	  //Wether is enabled or disabled
	};

} //namespace RecklessDriver
