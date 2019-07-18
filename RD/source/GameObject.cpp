/*
	class GameObject: Base class for all the objects of the game.
		The game manager will interface with them.
*/

#include "GameObject.h"
#include <iostream>

//Operator ++ for the Game object type
EGameObject operator++(EGameObject const e)
{
    switch (e) {
        case EGameObject::NO_INIT:
            return EGameObject::FIRE_HYDRANT;
        case EGameObject::FIRE_HYDRANT:
            return EGameObject::LETTER_BOX;
        case EGameObject::LETTER_BOX:
            return EGameObject::SEDAN;
        case EGameObject::SEDAN:
            return EGameObject::VAN;
        case EGameObject::VAN:
            return EGameObject::FIRE_HYDRANT;
        default:
            return EGameObject::NO_INIT;
    }
}

//**************************************************************************************
//Constructor
GameObject::GameObject(): _bActive(false), _bCrashed(false), _x(0), _y(0){}
	
//**************************************************************************************
//Destructor
GameObject::~GameObject() {}

//**************************************************************************************
//setters:
void GameObject::setName(std::string newName) { this->_name = newName; }
void GameObject::setTag(std::string newTag) { this->_tag = newTag; }
void GameObject::setType(EGameObject newType) { this->_type = newType; }
void GameObject::setX(unsigned int x) { this->_x = x; }
void GameObject::setY(unsigned int y) { this->_y = y; }
void GameObject::activate(){ _bActive = true; }
void GameObject::setChar(const char c) { this->_char = c; }

//**************************************************************************************
//Getters:
std::string GameObject::getName() const { return this->_name; }
std::string GameObject::getTag() const { return this->_tag; }
EGameObject GameObject::getType() const { return this->_type; }
unsigned int GameObject::getX() const { return this->_x; }
unsigned int GameObject::getY() const { return this->_y; }
bool GameObject::isCrashed() const { return this->_bCrashed; }
bool GameObject::isActive() const { return _bActive; }
char GameObject::getChar() const { return this->_char; }

//**************************************************************************************

void GameObject::reset()
{
    //it reached the end. Disable.
    _bActive = false;
    setY(0);
    setX(0);
    
}