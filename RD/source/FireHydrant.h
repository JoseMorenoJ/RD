#pragma once
/*
	class FireHydrant: behaviour of the side object of the type fire hydrant.
		Inherits from SideObject.
*/

#include "SideObject.h"

class FireHydrant :
	public SideObject
{
public:
	FireHydrant();
	~FireHydrant();

	void OnCollision(const GameObject &other) override;

private:
	void Fountain();
};
