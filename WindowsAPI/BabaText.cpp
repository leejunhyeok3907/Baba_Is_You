#include "BabaText.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaCamera.h"

bool ya::BabaText::m_IsMoveable = false;
bool ya::BabaText::m_IsPushable = false;
bool ya::BabaText::m_IsStop = false;

ya::BabaText::BabaText()
{
	SetName(L"BabaText");

	mImage = Resources::Load<Image>(L"Baba_Text", L"..\\Resources\\Image\\Game\\Baba_Text.bmp");

	mAnimator = new Animator();

	std::wstring AnimName[] = {
		L"Brown_BabaText",
		L"Red_BabaText",
	};

	for (int i = 0; i < 2; i++)
	{
		mAnimator->CreateAnimation(AnimName[i], mImage
			, Vector2(50.f * i, 0.0f), Vector2(50.0f, 50.0f)
			, Vector2(0.0f, 0.0f), 3, 0.3f);
	}

	mAnimator->Play(L"Red_BabaText", true);

	AddComponent(mAnimator);
}

ya::BabaText::~BabaText()
{
}

void ya::BabaText::Tick()
{
	BasedObject::Tick();
}

void ya::BabaText::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ya::BabaText::Move(eDir _dir, bool pushed)
{
}
