/*
	class GameObject: Base class for all the objects of the game.
		The game manager will interface with them.
*/

#include "GameObject.h"
#include <iostream>

//**************************************************************************************
//Constructor
GameObject::GameObject() {}
	
//**************************************************************************************
//Destructor
GameObject::~GameObject() {}

//**************************************************************************************
//Setters:
void GameObject::SetName(std::string newName) { this->_name = newName; }
void GameObject::SetTag(std::string newTag) { this->_tag = newTag; }
void GameObject::SetType(EGameObject newType) { this->_type = newType; }
void GameObject::SetX(unsigned int x) { this->_x = x; }
void GameObject::SetY(unsigned int y) { this->_y = y; }

//**************************************************************************************
//Getters:
std::string GameObject::GetName() const { return this->_name; }
std::string GameObject::GetTag() const { return this->_tag; }
EGameObject GameObject::GetType() const { return this->_type; }
unsigned int GameObject::GetX() const { return this->_x; }
unsigned int GameObject::GetY() const { return this->_y; }

