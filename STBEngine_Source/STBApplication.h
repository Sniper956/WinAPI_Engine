#pragma once
#include "Commonincllude.h"



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
		float mX;
		float mY;
	};


}


