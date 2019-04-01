#pragma once
/*
	class GameObject: Base class for all the objects of the game.
		The game manager will interface with them.

	enum EGameObjectType: List of the different possible objects that a Game Object can be.
*/

#include <string>

/* Why a namespace? 
	1. Prevent name clashes.
	2. Divide the application into manageable chunks.
	3. Searching/locating classes or other types.
	4. It DOESN'T encapsulate.
*/
namespace RecklessDriver {

	typedef enum EGameObjectType
	{
		NO_INIT = 0,
		PLAYER = 1,

		SIDE_OBJECT = 10,
		FIRE_HYDRANT = 11,
		LETTER_BOX = 12,

		TRAFFIC = 20,
		SEDAN = 21,
		VAN = 22
	};

	class GameObject
	{
	public:
		//TODO: constsructor with the EGameObjectType
		GameObject();
		~GameObject();

		void SetName(std::string);
		void SetTag(std::string);
		void SetType(EGameObjectType);

		std::string GetName() const;
		std::string GetTag() const;
		EGameObjectType GetType() const;


		//not pure virtual: we don't want to implement OnCollision in objects that the player cannot crash with.
		virtual void OnCollision(const GameObject &other);

	protected:
		EGameObjectType _type;
	private:
		std::string _name; //To uniquely identify a game object
		std::string _tag;  //To uniquely identify a game object group: Traffic, Side Objects, Player.
		
	};

} //namespace RecklessDriver
