#pragma once
#include "Commonincllude.h"

namespace STB
{
	class GameObjectRed
	{
	public:
		GameObjectRed();
		~GameObjectRed();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);


	private:

		float mX;
		float mY;

	};
}


