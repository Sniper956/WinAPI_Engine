#pragma once
#include "Commonincllude.h"


namespace STB
{
	class Time
	{
	public:

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequecy;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
	};

}

