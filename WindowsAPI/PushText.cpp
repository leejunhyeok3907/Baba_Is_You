#include "PushText.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaCamera.h"

bool ya::PushText::m_IsMoveable = false;
bool ya::PushText::m_IsPushable = false;
bool ya::PushText::m_IsStop = false;

ya::PushText::PushText()
{
	SetName(L"PushText");

	mImage = Resources::Load<Image>(L"Push_Text", L"..\\Resources\\Image\\Game\\Push_Text.bmp");

	mAnimator = new Animator();

	std::wstring AnimName[] = {
		L"White_PushText",
		L"DarkGreen_PushText",
		L"Green_PushText",
	};

	for (int i = 0; i < 3; i++)
	{
		mAnimator->CreateAnimation(AnimName[i], mImage
			, Vector2(50.f * i, 0.0f), Vector2(50.0f, 50.0f)
			, Vector2(0.0f, 0.0f), 3, 0.3f);
	}

	mAnimator->Play(L"White_PushText", true);

	AddComponent(mAnimator);
}

ya::PushText::~PushText()
{
}

void ya::PushText::Tick()
{
	BasedObject::Tick();
}

void ya::PushText::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ya::PushText::Move(eDir _dir, bool pushed)
{
}
