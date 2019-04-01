#pragma once
/*
	class LetterBox: behaviour of the side object of the type letter box.
		Inherits from SideObject.
*/

#include "SideObject.h"

namespace RecklessDriver {

	class LetterBox :
		public SideObject
	{
	public:
		LetterBox();
		~LetterBox();

		void OnCollision(const GameObject &other) override;

	private:
		void LettersFlying();

	};
}
