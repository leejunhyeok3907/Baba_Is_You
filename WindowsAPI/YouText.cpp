#include "YouText.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaCamera.h"

bool ya::YouText::m_IsMoveable = false;
bool ya::YouText::m_IsPushable = false;
bool ya::YouText::m_IsStop = false;

ya::YouText::YouText()
{
	SetName(L"YouText");

	mImage = Resources::Load<Image>(L"You_Text", L"..\\Resources\\Image\\Game\\You_Text.bmp");

	mAnimator = new Animator();

	std::wstring AnimName[] = {
		L"White_You",
		L"Brown_You",
		L"Red_You",
	};

	for (int i = 0; i < 3; i++)
	{
		mAnimator->CreateAnimation(AnimName[i], mImage
			, Vector2(50.f * i, 0.0f), Vector2(50.0f, 50.0f)
			, Vector2(0.0f, 0.0f), 3, 0.3f);
	}

	mAnimator->Play(L"White_You", true);

	AddComponent(mAnimator);
}

ya::YouText::~YouText()
{
}

void ya::YouText::Tick()
{
	BasedObject::Tick();
}

void ya::YouText::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ya::YouText::Move(eDir _dir, bool pushed)
{
}
