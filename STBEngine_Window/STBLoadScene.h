#pragma once

#include "..\\STBEngine_Source\\STBSceneManager.h"
#include "STBPlayScene.h"


namespace STB
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"playScene");
	}
}
