#include "Rock.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaCamera.h"

bool ya::Rock::m_IsMoveable = false;
bool ya::Rock::m_IsPushable = false;
bool ya::Rock::m_IsStop = true;

ya::Rock::Rock()
{
	SetName(L"RockObj");

	mImage = Resources::Load<Image>(L"Rock", L"..\\Resources\\Image\\Game\\Rock.bmp");

	mAnimator = new Animator();

	std::wstring AnimName[] = {
		L"Rock",
	};

	mAnimator->CreateAnimation(L"Rock", mImage
		, Vector2(0.f, 0.0f), Vector2(50.0f, 50.0f)
		, Vector2(0.0f, 0.0f), 3, 0.2f);

	mAnimator->Play(L"Rock", true);

	AddComponent(mAnimator);
}

ya::Rock::~Rock()
{
}

void ya::Rock::Tick()
{
	BasedObject::Tick();
}

void ya::Rock::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ya::Rock::Move(eDir _dir, bool pushed)
{
}
