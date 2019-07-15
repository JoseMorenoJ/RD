#pragma once
/*
	class GameObject: Base class for all the objects of the game.
		The game manager will interface with them.

	enum EGameObjectType: List of the different possible objects that a Game Object can be.
*/

#include <string>

typedef enum
{
	NO_INIT = 0,
	PLAYER = 1,

	SIDE_OBJECT = 10,
	FIRE_HYDRANT = 11,
	LETTER_BOX = 12,

	TRAFFIC = 20,
	SEDAN = 21,
	VAN = 22
}EGameObject;

EGameObject operator++(EGameObject const);

class GameObject
{
public:
	//TODO: constsructor with the EGameObjectType
	GameObject();
	virtual ~GameObject();

	void SetName(std::string);
	void SetTag(std::string);
	void SetType(EGameObject);
    void SetX(unsigned int x);
    void SetY(unsigned int y);

	std::string GetName() const;
	std::string GetTag() const;
	EGameObject GetType() const;
    unsigned int GetX() const;
    unsigned int GetY() const;
    bool isActive() const;

    // has to be defined in the sub classes.
    virtual void OnCollision(const GameObject &other) = 0;

protected:
	EGameObject _type;
private:
	std::string _name; //To uniquely identify a game object
	std::string _tag;  //To uniquely identify a game object group: Traffic, Side Objects, Player.
    bool _active; //Is it in or out of the screen
    //Position in the grid
    unsigned int _x;
    unsigned int _y;
		
};
