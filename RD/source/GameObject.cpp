/*
	class GameObject: Base class for all the objects of the game.
		The game manager will interface with them.
*/

#include "GameObject.h"

namespace RecklessDriver {

	//Setters:
	void GameObject::SetName(std::string newName) { this->_name = newName; }
	void GameObject::SetTag(std::string newTag) { this->_tag = newTag; }
	void GameObject::SetEnabled(bool newEnabled) { this->_enabled = newEnabled; }
	//Getters:
	const std::string GameObject::GetName() const { return this->_name; }
	const std::string GameObject::GetTag() const { return this->_tag; }
	bool GameObject::IsEnabled() const { return this->_enabled; }

	//Specifies the behaviour when two GameObject collide. Will be overriden when necessary.
	void GameObject::OnCollision(const GameObject &other)
	{
		return;
	}
}//namespace RecklessDriver