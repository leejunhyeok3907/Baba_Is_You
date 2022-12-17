#include "yaPlayScene.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaApplication.h"

#include "BasedObject.h"
#include "Baba.h"
#include "Rock.h"

#include "IsText.h"
#include "AndText.h"
#include "PullText.h"
#include "PushText.h"
#include "StopText.h"
#include "WinText.h"
#include "YouText.h"
#include "RockText.h"
#include "BabaText.h"

namespace ya
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		m_map = std::vector<std::vector<BasedObject*>>(5, std::vector<BasedObject*>(10, nullptr));
	}

	void PlayScene::Tick()
	{
		Scene::Tick();

		KeyCheck();

		if (KEY_DOWN(eKeyCode::K))
		{
			Baba::SetMoveable(true);
		}

		if (KEY_DOWN(eKeyCode::L))
		{
			Baba::SetMoveable(false);
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		WindowData mainWidnow = Application::GetInstance().GetWindowData();

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Play Scene");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen);

		RenderGrid(hdc);
	}
	
	void PlayScene::Enter()
	{
		SetToMap(1, 1, eGameObject::Baba);//
		SetToMap(1, 2, eGameObject::Text_Baba);//
		SetToMap(1, 3, eGameObject::Text_And);//
		SetToMap(1, 4, eGameObject::Text_Is);//
		SetToMap(2, 1, eGameObject::Text_Pull);//
		SetToMap(2, 2, eGameObject::Text_Push);//
		SetToMap(2, 3, eGameObject::Text_Rock);//
		SetToMap(2, 4, eGameObject::Text_Stop);//
		SetToMap(3, 1, eGameObject::Text_Win);//
		SetToMap(3, 2, eGameObject::Text_You);//
		SetToMap(3, 3, eGameObject::Rock);
	}

	void PlayScene::Exit()
	{

	}

	void PlayScene::KeyCheck()
	{
		if (KEY_DOWN(eKeyCode::W))
		{
			for (auto iter = m_map.begin(); iter != m_map.end(); iter++)
			{
				for (auto iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++)
				{
					if ((*iter2) && (*iter2)->IsMoveAble())
					{
						updateMove(eDir::UP, iter2);
					}
				}
			}
		}

		if (KEY_DOWN(eKeyCode::S))
		{
			for (auto iter = m_map.begin(); iter != m_map.end(); iter++)
			{
				for (auto iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++)
				{
					if ((*iter2) && (*iter2)->IsMoveAble())
					{
						updateMove(eDir::DOWN, iter2);
					}
				}
			}
		}

		if (KEY_DOWN(eKeyCode::A))
		{
			for(auto iter=m_map.begin(); iter!=m_map.end(); iter++)
			{
				for (auto iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++)
				{
					if ((*iter2) && (*iter2)->IsMoveAble())
					{
						updateMove(eDir::LEFT, iter2);
					}
				}
			}
		}

		if (KEY_DOWN(eKeyCode::D))
		{
			for (auto iter = m_map.begin(); iter != m_map.end(); iter++)
			{
				for (auto iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++)
				{
					if ((*iter2) && (*iter2)->IsMoveAble())
					{
						updateMove(eDir::RIGHT, iter2);
					}
				}
			}
		}
	}

	bool PlayScene::Is_In_map(int x, int y)
	{
		return (y >= 0 && y < m_map.size()) && (x >= 0 && x < m_map[0].size());
	}

	void PlayScene::updateMove(eDir _dir, std::vector<BasedObject*>::iterator _iter)
	{
		static bool CannotMove = false;
		
		Vector2 MapPos = (*_iter)->GetMapPos();

		int next_x = MapPos.x + MoveDir[(int)_dir][1];
		int next_y = MapPos.y + MoveDir[(int)_dir][0];

		//다음 좌표가 맵 밖이 아닐 경우에만
		if (Is_In_map(next_x, next_y))
		{
			//if (m_map[next_y][next_x])
			//{
			//	//멈춰야할 객체가 있는경우 해당방향으로 업데이트 중단
			//	if (!m_map[next_y][next_x]->IsStop())
			//	{
			//		CannotMove = true;
			//		return;
			//	}
			//	//밀수있는 객체일경우 해당 방향으로 한번 더 업데이트
			//	if (m_map[next_y][next_x]->IsPushable()) updateMove(_dir, x + MoveDir[(int)_dir][1], y + MoveDir[(int)_dir][0]);
			//}

			if (CannotMove) return;

			(*_iter)->Move(_dir);
			(*_iter)->SetMapPos(Vector2({ (float)next_x, (float)next_y }));
			//m_map[next_y][next_x] = (*_iter);
			//m_map[MapPos.y][MapPos.x] = nullptr;
		}
	}

	void PlayScene::RenderGrid(HDC hdc)
	{
		WindowData mainWidnow = Application::GetInstance().GetWindowData();

		int pos_x = (mainWidnow.width / 2) - ((m_map[0].size() / 2) * TILE_SIZE * TILE_SCALE);
		int pos_y = (mainWidnow.height / 2) - ((m_map.size() / 2) * TILE_SIZE * TILE_SCALE);

		int lastpos_x = pos_x + ((TILE_SIZE * TILE_SCALE) * m_map[0].size());
		int lastpos_y = pos_y + ((TILE_SIZE * TILE_SCALE) * m_map.size());

		HPEN hPrevPen = (HPEN)SelectObject(hdc, Application::GetInstance().GetPen(ePenColor::Green));

		Rectangle(hdc, pos_x - 10, pos_y - 10, pos_x + 10, pos_y + 10);
		Rectangle(hdc, lastpos_x - 10, lastpos_y - 10, lastpos_x + 10, lastpos_y + 10);

		for (int i = pos_x; i <= lastpos_x; i += (TILE_SIZE * TILE_SCALE))
		{
			MoveToEx(hdc, i, pos_y, nullptr);
			LineTo(hdc, i, lastpos_y);
		}

		for (int j = pos_y; j <= lastpos_y; j += (TILE_SIZE * TILE_SCALE))
		{
			MoveToEx(hdc, pos_x, j, nullptr);
			LineTo(hdc, lastpos_x, j);
		}

		SelectObject(hdc, hPrevPen);
	}

	void PlayScene::SetToMap(int idx_x, int idx_y, eGameObject obj)
	{
		WindowData mainWidnow = Application::GetInstance().GetWindowData();
		int pos_x = (mainWidnow.width / 2) - ((m_map[0].size() / 2) * TILE_SIZE * TILE_SCALE);
		int pos_y = (mainWidnow.height / 2) - ((m_map.size() / 2) * TILE_SIZE * TILE_SCALE);

		int curpos_x = pos_x + (idx_x * (TILE_SIZE * TILE_SCALE)) + (TILE_SIZE * TILE_SCALE) / 2;
		int curpos_y = pos_y + (idx_y * (TILE_SIZE * TILE_SCALE)) + (TILE_SIZE * TILE_SCALE) / 2;

		BasedObject* Object = nullptr;

		if (eGameObject::Baba == obj)
		{
			Object = new Baba;
		}
		else if (eGameObject::Rock == obj)
		{
			Object = new Rock;
		}
		else if (eGameObject::Text_You == obj)
		{
			Object = new YouText;
		}
		else if (eGameObject::Text_Baba == obj)
		{
			Object = new BabaText;
		}
		else if (eGameObject::Text_And == obj)
		{
			Object = new AndText;
		}
		else if (eGameObject::Text_Is == obj)
		{
			Object = new IsText;
		}
		else if (eGameObject::Text_Pull == obj)
		{
			Object = new PullText;
		}
		else if (eGameObject::Text_Push == obj)
		{
			Object = new PushText;
		}
		else if (eGameObject::Text_Rock == obj)
		{
			Object = new RockText;
		}
		else if (eGameObject::Text_Stop == obj)
		{
			Object = new StopText;
		}
		else if (eGameObject::Text_Win == obj)
		{
			Object = new WinText;
		}

		if (Object)
		{
			Object->SetPos({ (float)curpos_x, (float)curpos_y });

			m_map[idx_y][idx_x] = Object;
			Object->SetMapPos(Vector2({ (float)idx_x, (float)idx_y }));

			AddGameObject(Object, eColliderLayer::Player);
		}
	}
}
