#pragma once
#include "STBEntity.h"
#include "GameObject.h"
namespace STB
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		std::vector<GameObject*> mGameObject;
	};
}
