#include "GameObjectRed.h"

namespace STB
{
	GameObjectRed::GameObjectRed() :mX(0.0f), mY(0.0f)
	{

	}

	GameObjectRed::~GameObjectRed()
	{

	}

	void GameObjectRed::Update()
	{
		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.01f;
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY += 0.01f;
		}
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.01f;
		}
	}


	void GameObjectRed::LateUpdate()
	{

	}

	void GameObjectRed::Render(HDC hdc)
	{
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrsuh = (HBRUSH)SelectObject(hdc, redBrush);

		Ellipse(hdc, 1400 + mX, 700 + mY, 1500 + mX, 800 + mY);

		SelectObject(hdc,oldBrsuh);
		DeleteObject(redBrush);
	}

}

