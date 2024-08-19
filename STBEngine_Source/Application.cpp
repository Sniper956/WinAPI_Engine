#include "STBApplication.h"
#include "STBInput.h"
#include "STBtime.h"
#include "STBSceneManager.h"

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
	void Application::initialize(HWND hWnd, UINT width, UINT height)
	{
		adjustWindowRect(hWnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		SceneManager::Initialize();
	

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

		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		clearRenderTarget();
		
		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mhdc);
	}
	void Application::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}
	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mhwnd = hwnd;
		mhdc = GetDC(hwnd);

		RECT rect = { 0,0,width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mhwnd, nullptr, 0, 0
			, mWidth, mHeight, 0);


		ShowWindow(mhwnd, true);
	}
	void Application::createBuffer(UINT width, UINT height)
	{
		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBuffer = CreateCompatibleBitmap(mhdc, width, height);

		// 백버퍼를 가릴킬 DC 생성
		mBackHdc = CreateCompatibleDC(mhdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);
	}
	void Application::initializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}
}