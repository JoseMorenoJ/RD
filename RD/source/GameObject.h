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

EGameObject nextGO(EGameObject& e);

class GameObject
{
public:
	//TODO: constsructor with the EGameObjectType
	GameObject();
	virtual ~GameObject();

	void setName(std::string);
	void setTag(std::string);
	void setType(EGameObject);
    void setX(const int x);
    void setY(const int y);
    void activate();
    void setChar(const char);

	std::string getName() const;
	std::string getTag() const;
	EGameObject getType() const;
    int getX() const;
    int getY() const;
    bool isActive() const;
    bool isCrashed() const;
    char getChar() const;
    
    // has to be defined in the sub classes.
    virtual void onCollision(const GameObject &other) = 0;
    virtual void update() = 0;
    
    // an object has reached the end, disable it.
    void reset();

protected:
    bool _bCrashed; // if it is crashed it will give the bonus points

private:
    EGameObject _type;
	std::string _name; //To uniquely identify a game object
	std::string _tag;  //To uniquely identify a game object group: Traffic, Side Objects, Player.
    bool _bActive; //Is it in or out of the screen
    //Position in the grid
    int _x;
    int _y;
    char _char;
		
};
