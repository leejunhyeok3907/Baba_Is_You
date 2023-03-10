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
		// 모든씬들을 초기화
		// 다른씬에서 툴씬을 사용하려면 툴씬이 
		// 제일 우선적으로 생성되어야 한다.
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
		// 업캐스팅
		// 다운캐스팅

		//Scene* t = new LogoScene();
		//t->Initialize();
	}

	void SceneManager::Tick()
	{
		//현재 씬들을 update Tick
		mPlayScene->Tick();
	}

	void SceneManager::Render(HDC hdc)
	{
		//현재씬 렌더링
		mPlayScene->Render(hdc);
	}

	void SceneManager::DetroyGameObject()
	{
		ya::object::Release();
	}

	void SceneManager::Release()
	{
		// 프로그램 종료될떄 한번만 호출
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
