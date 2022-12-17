#include "RockText.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaCamera.h"

bool ya::RockText::m_IsMoveable = false;
bool ya::RockText::m_IsPushable = false;
bool ya::RockText::m_IsStop = false;

ya::RockText::RockText()
{
	SetName(L"RockText");

	mImage = Resources::Load<Image>(L"Rock_Text", L"..\\Resources\\Image\\Game\\Rock_Text.bmp");

	mAnimator = new Animator();

	std::wstring AnimName[] = {
		L"White_RockText",
		L"DarkGreen_RockText",
		L"Green_RockText",
	};

	for (int i = 0; i < 3; i++)
	{
		mAnimator->CreateAnimation(AnimName[i], mImage
			, Vector2(50.f * i, 0.0f), Vector2(50.0f, 50.0f)
			, Vector2(0.0f, 0.0f), 3, 0.3f);
	}

	mAnimator->Play(L"White_RockText", true);

	AddComponent(mAnimator);
}

ya::RockText::~RockText()
{
}

void ya::RockText::Tick()
{
	BasedObject::Tick();
}

void ya::RockText::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ya::RockText::Move(eDir _dir, bool pushed)
{
}
