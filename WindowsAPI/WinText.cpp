#include "WinText.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaCamera.h"

bool ya::WinText::m_IsMoveable = false;
bool ya::WinText::m_IsPushable = false;
bool ya::WinText::m_IsStop = false;

ya::WinText::WinText()
{
	SetName(L"WinText");

	mImage = Resources::Load<Image>(L"Win_Text", L"..\\Resources\\Image\\Game\\Win_Text.bmp");

	mAnimator = new Animator();

	std::wstring AnimName[] = {
		L"White_WinText",
		L"Brown_WinText",
		L"Yellow_WinText",
	};

	for (int i = 0; i < 3; i++)
	{
		mAnimator->CreateAnimation(AnimName[i], mImage
			, Vector2(50.f * i, 0.0f), Vector2(50.0f, 50.0f)
			, Vector2(0.0f, 0.0f), 3, 0.3f);
	}

	mAnimator->Play(L"White_WinText", true);

	AddComponent(mAnimator);
}

ya::WinText::~WinText()
{
}

void ya::WinText::Tick()
{
	BasedObject::Tick();
}

void ya::WinText::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ya::WinText::Move(eDir _dir, bool pushed)
{
}
