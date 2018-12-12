#include "GameObject.h"

namespace RecklessDriver {

	//Setters:
	void GameObject::SetName(std::string name) { this->name = name; }
	void GameObject::SetTag(std::string tag) { this->tag = tag; }
	void GameObject::SetEnabled(bool enabled) { this->enabled = enabled; }
	//Getters:
	const std::string GameObject::GetName() const { return this->name; }
	const std::string GameObject::GetTag() const { return this->tag; }
	bool GameObject::IsEnabled() const { return this->enabled; }

	//Specifies the behaviour when two GameObject collide. Will be overriden when necessary.
	void GameObject::OnCollision(const GameObject & other)
	{
		return;
	}
}//namespace RecklessDriver