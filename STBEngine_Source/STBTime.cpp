#include "STBTime.h"

namespace STB
{
	LARGE_INTEGER  Time::CpuFrequency = {};
	LARGE_INTEGER  Time::PrevFrequecy = {};
	LARGE_INTEGER  Time::CurrentFrequency = {};
	float  Time::DeltaTimeValue = 0.0f;


	void Time::Initialize()
	{
		// CPU ���� ������
		QueryPerformanceFrequency(&CpuFrequency);

		// ���α׷��� ���� ���� �� ���� ������
		QueryPerformanceCounter(&PrevFrequecy);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequecy.QuadPart);
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequecy.QuadPart = CurrentFrequency.QuadPart;

	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;

		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);

		int len = wcsnlen_s(str,50);


		TextOut(hdc, 0, 0, str, len);

	}
};