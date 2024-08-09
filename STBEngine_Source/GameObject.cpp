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
        // 색 브러쉬를 만들고 SelectObject를 통해서 사용할 브러쉬를 선택한다.
        // 파랑 브러쉬 생성
        HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));


        // 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

        HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

        SelectObject(hdc, oldPen);

      
        Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

        DeleteObject(redPen);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

        // 기본으로 자주사용 되는 GDI 오브젝트를 미리 DC안에 만들어두었는데
        // 그 오브젝트들을 스톡 오브젝트라고 한다.
        SelectObject(hdc, oldBrush);
        DeleteObject(brush);
        DeleteObject(redPen);

	}

	
	
}


