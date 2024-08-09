#include "GameObject.h"
#include "STBInput.h"
#include "STBTime.h"
namespace STB
{
	STB::GameObject::GameObject() : mX(0.0f), mY(0.0f)
	{

	}

	STB::GameObject::~GameObject()
	{
        //Do noy
	}

	void GameObject::Update()
	{
        const int speed = 100.f;
        if (Input::GetKey(eKeyCode::A) )
        {
            mX -= speed * Time::DeltaTime();
        }

        if (Input::GetKey(eKeyCode::D))
        {
            mX += speed * Time::DeltaTime();
        }

        if (Input::GetKey(eKeyCode::W))
        {
            mY -= speed * Time::DeltaTime();
        }

        if (Input::GetKey(eKeyCode::S))
        {
            mY += speed * Time::DeltaTime();
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


