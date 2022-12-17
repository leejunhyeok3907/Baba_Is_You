#pragma once
#include "yaScene.h"

#include "BasedObject.h"

namespace ya
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

	public:
		void KeyCheck();
		bool Is_In_map(int x, int y);
		void updateMove(eDir _dir, std::vector<BasedObject*>::iterator _iter);

	public:
		void RenderGrid(HDC hdc);
		void SetToMap(int idx_x, int idx_y, eGameObject obj);

	private:
		std::vector<std::vector<BasedObject*>> m_map;
	};

}
