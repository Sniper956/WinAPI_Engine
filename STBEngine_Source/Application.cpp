#include "STBApplication.h"
#include "STBInput.h"

namespace STB
{
	Application::Application() :
		mhwnd(nullptr)
		, mhdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBuffer(NULL)
      
    {


    }
    Application::~Application()
    {


    }
	void Application::initialize(HWND hwnd, UINT width, UINT height)
	{
		mhwnd = hwnd;
		mhdc = GetDC(hwnd);
		
		RECT rect = {0,0,width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mhwnd, nullptr, 0, 0
			, mWidth , mHeight, 0);


		ShowWindow(mhwnd, true);
		//mPlayer.SetPostion(0, 0);

		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBuffer = CreateCompatibleBitmap(mhdc, width, height);

		// 백버퍼를 가릴킬 DC 생성
		mBackHdc = CreateCompatibleDC(mhdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);

		Input::Initialize();
		Time::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		Input::Update();
		Time::Update();
        mPlayer.Update();
		//mPlayer2.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);


		Time::Render(mBackHdc);
        mPlayer.Render(mBackHdc);
		//mPlayer2.Render(mhdc);

		BitBlt(mhdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0,SRCCOPY);
	}
}