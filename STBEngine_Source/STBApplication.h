#pragma once
#include "Commonincllude.h"
#include "GameObject.h"


namespace STB
{
	class Application
	{
	public:
		Application();
		~Application();
		void initialize(HWND hwnd);
		void Run();


		void Update();
		void LateUpdate();
		void Render();


	private:
		HWND mhwnd;
		HDC mhdc;

		float mSpeed;

		// 플레이어
		//float mX;
		//float mY;
		GameObject mPlayer;
	};


}


