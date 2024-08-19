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

		void EllipsMakeCenter(HDC hdc, int x, int y);
		void SetEllipsePos(float x, float y) {this->mX = x,this->mY = y; };
		
		float GetX() { return mX; }
		float GetY() { return mY; }
		 

	private:

		 float mX;
		 float mY;
		 float mR;
	};
}


