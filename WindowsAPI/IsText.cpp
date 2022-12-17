#include "IsText.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaCamera.h"

bool ya::IsText::m_IsMoveable = false;
bool ya::IsText::m_IsPushable = false;
bool ya::IsText::m_IsStop = false;

ya::IsText::IsText()
{
	SetName(L"IsText");

	mImage = Resources::Load<Image>(L"Is_Text", L"..\\Resources\\Image\\Game\\Is_Text.bmp");

	mAnimator = new Animator();

	std::wstring AnimName[] = {
		L"White_IsText",
		L"Brown_IsText",
	};

	for (int i = 0; i < 2; i++)
	{
		mAnimator->CreateAnimation(AnimName[i], mImage
			, Vector2(50.f * i, 0.0f), Vector2(50.0f, 50.0f)
			, Vector2(0.0f, 0.0f), 3, 0.3f);
	}

	mAnimator->Play(L"White_IsText", true);

	AddComponent(mAnimator);
}

ya::IsText::~IsText()
{
}

void ya::IsText::Tick()
{
	BasedObject::Tick();
}

void ya::IsText::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ya::IsText::Move(eDir _dir, bool pushed)
{
}
