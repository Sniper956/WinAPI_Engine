#pragma once
#include "Commonincllude.h"
#include "GameObject.h"
#include "STBTime.h"


namespace STB
{
	class Application
	{
	public:
		Application();
		~Application();
		void initialize(HWND hwnd, UINT width, UINT height);
		void Run();


		void Update();
		void LateUpdate();
		void Render();


	private:
		HWND mhwnd;
		HDC mhdc;

		// �����״���� �׸���
		HDC mBackHdc;
		HBITMAP mBackBuffer;


		UINT mWidth;
		UINT mHeight;

	
		GameObject mPlayer;

	};


}


