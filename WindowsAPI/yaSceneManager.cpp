#include "yaSceneManager.h"
#include "yaLogoScene.h"
#include "yaTitleScene.h"
#include "yaPlayScene.h"
#include "yaEndScene.h"
#include "yaToolScene.h"
#include "yaObject.h"
#include "yaCollisionManager.h"

namespace ya
{
	Scene* SceneManager::mScenes[(UINT)eSceneType::Max] = {};
	Scene* SceneManager::mPlayScene = nullptr;
	eSceneType SceneManager::mType = eSceneType::Max;

	void SceneManager::Initialize()
	{
		// �������� �ʱ�ȭ
		// �ٸ������� ������ ����Ϸ��� ������ 
		// ���� �켱������ �����Ǿ�� �Ѵ�.
		mScenes[(UINT)eSceneType::Tool] = new ToolScene();
		mScenes[(UINT)eSceneType::Tool]->Initialize();
	
		mScenes[(UINT)eSceneType::Logo] = new LogoScene();
		mScenes[(UINT)eSceneType::Logo]->Initialize();

		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Title]->Initialize();

		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		mScenes[(UINT)eSceneType::Play]->Initialize();

		mScenes[(UINT)eSceneType::End] = new EndScene();
		mScenes[(UINT)eSceneType::End]->Initialize();

		ChangeScene(eSceneType::Play);
		// ��ĳ����
		// �ٿ�ĳ����

		//Scene* t = new LogoScene();
		//t->Initialize();
	}

	void SceneManager::Tick()
	{
		//���� ������ update Tick
		mPlayScene->Tick();
	}

	void SceneManager::Render(HDC hdc)
	{
		//����� ������
		mPlayScene->Render(hdc);
	}

	void SceneManager::DetroyGameObject()
	{
		ya::object::Release();
	}

	void SceneManager::Release()
	{
		// ���α׷� ����ɋ� �ѹ��� ȣ��
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			delete scene;
			scene = nullptr;
		}
	}

	void SceneManager::ChangeScene(eSceneType type)
	{
		if (mScenes[(UINT)type] == nullptr)
			return;

		mType = type;

		CollisionManager::Clear();
		mPlayScene->Exit();
		mPlayScene = mScenes[(UINT)type];
		
		mPlayScene->Enter();
	}


}
