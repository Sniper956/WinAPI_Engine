#include "GameObjectRed.h"

namespace STB
{
	GameObjectRed::GameObjectRed() :mX(0.0f), mY(0.0f),mR(20.f)
	{

	}

	GameObjectRed::~GameObjectRed()
	{

	}

	void GameObjectRed::Update()
	{
		mY -= 1.f;
	}


	void GameObjectRed::LateUpdate()
	{

	}

	void GameObjectRed::Render(HDC hdc)
	{
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrsuh = (HBRUSH)SelectObject(hdc, redBrush);

		EllipsMakeCenter(hdc, mX, mY);
	
		DeleteObject(redBrush);
	}

	void GameObjectRed::EllipsMakeCenter(HDC hdc, int x, int y)
	{
		Ellipse(hdc, x-mR/ 2, y-mR/ 2 , x + mR/2 , y + mR/2);
	}

	
	
}

