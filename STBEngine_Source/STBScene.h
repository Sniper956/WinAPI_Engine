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

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);



	private:
		std::vector<GameObject*> mGameObject;
	};
}
