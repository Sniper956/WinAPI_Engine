#pragma once
#include "Commonincllude.h"
#include "GameObjectRed.h"

namespace STB
{
	// Actor
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);
	   
		void BulletsUpdate();
		void BulletsRender(HDC hdc);
		void SetPostion(float x, float y)
		{
			mX = x;
			mY = y;
		}
	   
		float GetPostionX() { return mX; }
		
		float GetPostionY() { return mY; }

	private:
		// 게임오브젝트의 좌표
		float mX;
		float mY;

		std::vector<GameObjectRed*> Bullets;
		std::vector<GameObjectRed*>::iterator iterBullets;
	};


}

