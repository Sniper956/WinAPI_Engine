#include "STBApplication.h"

namespace STB
{
    Application::Application() : mhwnd(nullptr), mhdc(nullptr), mSpeed(0.0f), mX(0.0f), mY(0.0f)
    {


    }
    Application::~Application()
    {


    }
    void Application::initialize(HWND hwnd)
	{
		mhwnd = hwnd;
		mhdc = GetDC(hwnd);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
        mSpeed += 0.01f;

        // 내가 오른쪽 키를 입력받았다면
        // x 좌표가 플러스 
        // 왼쪽 -> x 가 마이너스
        // 위아래는 y가 플러스 마이너스
        
        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
            mX -= 0.01f;
        }
        
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
            mX += 0.01f;
        }

        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            mY -= 0.01f;
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            mY += 0.01f;
        }



	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
        // 색 브러쉬를 만들고 SelectObject를 통해서 사용할 브러쉬를 선택한다.
           // 파랑 브러쉬 생성
        HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));

      
        // 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
        HBRUSH oldBrush = (HBRUSH)SelectObject(mhdc, brush);

        HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
        HPEN oldPen = (HPEN)SelectObject(mhdc, redPen);
     
        SelectObject(mhdc, oldPen);

        Rectangle(mhdc, 100 + mX  ,100 + mY, 200 + mX, 200 + mY);

        DeleteObject(redPen);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

        // 기본으로 자주사용 되는 GDI 오브젝트를 미리 DC안에 만들어두었는데
        // 그 오브젝트들을 스톡 오브젝트라고 한다.
        SelectObject(mhdc, oldBrush);
        DeleteObject(brush);
        DeleteObject(redPen);

	}
}