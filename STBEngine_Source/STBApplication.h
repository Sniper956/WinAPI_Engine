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
		void initialize(HWND hWnd, UINT width, UINT height);
		void Run();


		void Update();
		void LateUpdate();
		void Render();


	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	private:
		HWND mhwnd;
		HDC mhdc;


		// �����״���� �׸���
		HDC mBackHdc;
		HBITMAP mBackBuffer;


		UINT mWidth;
		UINT mHeight;

		// �÷��̾�
		GameObject mPlayer;

		std::vector<GameObject*> mGameObjects;

	};


}


