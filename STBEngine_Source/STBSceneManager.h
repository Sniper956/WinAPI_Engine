#pragma once
#include "STBEntity.h"
#include "STBScene.h"


namespace STB
{
	class SceneManager
	{
	public:
			template <typename T>
			static Scene* CreateScene(std::wstring& name)
			{
				T* scene = new T();
				scene->SetName(name);
				scene->Initialize();


				mScene.insert(make_pair(name, scene));

			}


		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		

	private:
		//static std::vector<Scene*> mScene;
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}

