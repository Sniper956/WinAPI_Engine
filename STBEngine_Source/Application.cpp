#include "STBApplication.h"

namespace STB
{
    Application::Application() : 
        mhwnd(nullptr)
        , mhdc(nullptr)
        , mSpeed(0.0f)
      
    {


    }
    Application::~Application()
    {


    }
    void Application::initialize(HWND hwnd)
	{
		mhwnd = hwnd;
		mhdc = GetDC(hwnd);
       // mPlayer.SetPostion(0, 0);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
        mPlayer.Update();
		mPlayer2.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
        mPlayer.Render(mhdc);  
		mPlayer2.Render(mhdc);
	}
}