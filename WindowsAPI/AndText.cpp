#include "AndText.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaCamera.h"

bool ya::AndText::m_IsMoveable = false;
bool ya::AndText::m_IsPushable = false;
bool ya::AndText::m_IsStop = false;

ya::AndText::AndText()
{
	SetName(L"AndText");

	mImage = Resources::Load<Image>(L"And_Text", L"..\\Resources\\Image\\Game\\And_Text.bmp");

	mAnimator = new Animator();

	std::wstring AnimName[] = {
		L"White_AndText",
		L"Brown_AndText",
	};

	for (int i = 0; i < 2; i++)
	{
		mAnimator->CreateAnimation(AnimName[i], mImage
			, Vector2(50.f * i, 0.0f), Vector2(50.0f, 50.0f)
			, Vector2(0.0f, 0.0f), 3, 0.3f);
	}

	mAnimator->Play(L"White_AndText", true);

	AddComponent(mAnimator);
}

ya::AndText::~AndText()
{
}

void ya::AndText::Tick()
{
	BasedObject::Tick();
}

void ya::AndText::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ya::AndText::Move(eDir _dir, bool pushed)
{
}
