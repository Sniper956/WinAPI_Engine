#include "GameObject.h"

namespace STB
{
	STB::GameObject::GameObject() : mX(0.0f), mY(0.0f)
	{

	}

	STB::GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
  
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

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
        // �� �귯���� ����� SelectObject�� ���ؼ� ����� �귯���� �����Ѵ�.
        // �Ķ� �귯�� ����
        HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));


        // �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

        HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

        SelectObject(hdc, oldPen);

      
        Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

        DeleteObject(redPen);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...

        // �⺻���� ���ֻ�� �Ǵ� GDI ������Ʈ�� �̸� DC�ȿ� �����ξ��µ�
        // �� ������Ʈ���� ���� ������Ʈ��� �Ѵ�.
        SelectObject(hdc, oldBrush);
        DeleteObject(brush);
        DeleteObject(redPen);

	}

	
	
}


