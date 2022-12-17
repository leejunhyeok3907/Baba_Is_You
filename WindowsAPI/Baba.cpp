#include "Baba.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaCamera.h"

bool ya::Baba::m_IsMoveable = false;
bool ya::Baba::m_IsPushable = false;
bool ya::Baba::m_IsStop = false;

ya::Baba::Baba()
	: m_movecnt(0)
{
	SetName(L"Player");

	mImage = Resources::Load<Image>(L"PlayerTest", L"..\\Resources\\Image\\Game\\baba.bmp");

	mAnimator = new Animator();

	AnimName.push_back(L"MoveRight1");
	AnimName.push_back(L"MoveRight2");
	AnimName.push_back(L"MoveRight3");
	AnimName.push_back(L"MoveRight4");

	AnimName.push_back(L"MoveUp1");
	AnimName.push_back(L"MoveUp2");
	AnimName.push_back(L"MoveUp3");
	AnimName.push_back(L"MoveUp4");

	AnimName.push_back(L"MoveLeft1");
	AnimName.push_back(L"MoveLeft2");
	AnimName.push_back(L"MoveLeft3");
	AnimName.push_back(L"MoveLeft4");

	AnimName.push_back(L"MoveDown1");
	AnimName.push_back(L"MoveDown2");
	AnimName.push_back(L"MoveDown3");
	AnimName.push_back(L"MoveDown4");

	for (int i = 0; i < AnimName.size(); i++)
	{
		mAnimator->CreateAnimation(AnimName[i], mImage
			, Vector2(49.0f * i + ((i + 1) / 4 * 3), 0.0f), Vector2(49.0f, 49.0f)
			, Vector2(0.0f, 0.0f), 3, 0.2f);
	}

	mAnimator->Play(L"MoveRight1", true);

	AddComponent(mAnimator);
}

ya::Baba::~Baba()
{
}

void ya::Baba::Tick()
{
	BasedObject::Tick();
}

void ya::Baba::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ya::Baba::Move(eDir _dir, bool pushed)
{
	if (!m_MoveOnce)
	{
		m_movecnt++;
		m_movecnt %= 4;

		if (eDir::UP == _dir)
		{
			mAnimator->Play(AnimName[4 + m_movecnt], true);

			Vector2 pos = GetPos();
			mDest = Vector2(pos.x, pos.y - (TILE_SIZE * TILE_SCALE));
			m_MoveOnce = true;
		}
		else if (eDir::DOWN == _dir)
		{
			mAnimator->Play(AnimName[12 + m_movecnt], true);

			Vector2 pos = GetPos();
			mDest = Vector2(pos.x, pos.y + (TILE_SIZE * TILE_SCALE));
			m_MoveOnce = true;
		}
		else if (eDir::LEFT == _dir)
		{
			mAnimator->Play(AnimName[8 + m_movecnt], true);

			Vector2 pos = GetPos();
			mDest = Vector2(pos.x - (TILE_SIZE * TILE_SCALE), pos.y);
			m_MoveOnce = true;
		}
		else if (eDir::RIGHT == _dir)
		{
			mAnimator->Play(AnimName[m_movecnt], true);

			Vector2 pos = GetPos();
			mDest = Vector2(pos.x + (TILE_SIZE * TILE_SCALE), pos.y);
			m_MoveOnce = true;
		}
	}
}
