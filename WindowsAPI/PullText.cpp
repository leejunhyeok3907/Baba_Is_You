#include "PullText.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaCamera.h"

bool ya::PullText::m_IsMoveable = false;
bool ya::PullText::m_IsPushable = false;
bool ya::PullText::m_IsStop = false;

ya::PullText::PullText()
{
	SetName(L"PullText");

	mImage = Resources::Load<Image>(L"Pull_Text", L"..\\Resources\\Image\\Game\\Pull_Text.bmp");

	mAnimator = new Animator();

	std::wstring AnimName[] = {
		L"White_PullText",
		L"DarkGreen_PullText",
		L"Green_PullText",
	};

	for (int i = 0; i < 3; i++)
	{
		mAnimator->CreateAnimation(AnimName[i], mImage
			, Vector2(50.f * i, 0.0f), Vector2(50.0f, 50.0f)
			, Vector2(0.0f, 0.0f), 3, 0.3f);
	}

	mAnimator->Play(L"DarkGreen_PullText", true);

	AddComponent(mAnimator);
}

ya::PullText::~PullText()
{
}

void ya::PullText::Tick()
{
	BasedObject::Tick();
}

void ya::PullText::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ya::PullText::Move(eDir _dir, bool pushed)
{
}
