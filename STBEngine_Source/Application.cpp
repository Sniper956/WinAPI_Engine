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

        // ���� ������ Ű�� �Է¹޾Ҵٸ�
        // x ��ǥ�� �÷��� 
        // ���� -> x �� ���̳ʽ�
        // ���Ʒ��� y�� �÷��� ���̳ʽ�
        
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
        // �� �귯���� ����� SelectObject�� ���ؼ� ����� �귯���� �����Ѵ�.
           // �Ķ� �귯�� ����
        HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));

      
        // �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
        HBRUSH oldBrush = (HBRUSH)SelectObject(mhdc, brush);

        HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
        HPEN oldPen = (HPEN)SelectObject(mhdc, redPen);
     
        SelectObject(mhdc, oldPen);

        Rectangle(mhdc, 100 + mX  ,100 + mY, 200 + mX, 200 + mY);

        DeleteObject(redPen);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...

        // �⺻���� ���ֻ�� �Ǵ� GDI ������Ʈ�� �̸� DC�ȿ� �����ξ��µ�
        // �� ������Ʈ���� ���� ������Ʈ��� �Ѵ�.
        SelectObject(mhdc, oldBrush);
        DeleteObject(brush);
        DeleteObject(redPen);

	}
}