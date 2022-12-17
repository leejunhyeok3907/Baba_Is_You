#include "StopText.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaCamera.h"

bool ya::StopText::m_IsMoveable = false;
bool ya::StopText::m_IsPushable = false;
bool ya::StopText::m_IsStop = false;

ya::StopText::StopText()
{
	SetName(L"StopText");

	mImage = Resources::Load<Image>(L"Stop_Text", L"..\\Resources\\Image\\Game\\Stop_Text.bmp");

	mAnimator = new Animator();

	std::wstring AnimName[] = {
		L"White_StopText",
		L"DarkGreen_StopText",
		L"Green_StopText",
	};

	for (int i = 0; i < 3; i++)
	{
		mAnimator->CreateAnimation(AnimName[i], mImage
			, Vector2(50.f * i, 0.0f), Vector2(50.0f, 50.0f)
			, Vector2(0.0f, 0.0f), 3, 0.3f);
	}

	mAnimator->Play(L"White_StopText", true);

	AddComponent(mAnimator);
}

ya::StopText::~StopText()
{
}

void ya::StopText::Tick()
{
	BasedObject::Tick();
}

void ya::StopText::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ya::StopText::Move(eDir _dir, bool pushed)
{
}
