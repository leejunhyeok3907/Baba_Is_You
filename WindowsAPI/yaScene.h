#pragma once
#include "Common.h"
#include "yaEntity.h"


namespace ya
{


	class GameObject;
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		virtual void Enter();
		virtual void Exit();

		void AddGameObject(GameObject* object, eColliderLayer type);


		std::vector<GameObject*>& GetGameObjects(eColliderLayer type) { return mObjects[(UINT)type]; }
		std::vector<std::vector<GameObject*>>& GetGameObjects() { return mObjects; }

	private:
		std::vector<std::vector<GameObject*>> mObjects;

	};

	//typedef std::vector<std::vector<GameObject*>> GameObjects;
	//typedef std::vector<GameObject*> LayerObjects;
}

