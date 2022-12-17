#include "BasedObject.h"
#include "yaAnimation.h"
#include "yaAnimator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaCamera.h"

ya::BasedObject::BasedObject()
{
}

ya::BasedObject::~BasedObject()
{
}

void ya::BasedObject::Tick()
{
	GameObject::Tick();

	if (m_MoveOnce)
	{
		Vector2 pos = GetPos();

		pos = math::lerp(pos, mDest, 0.1f);

		float value = (pos - mDest).Length();
		if (value < 1.0f)
		{
			pos = mDest;
			m_MoveOnce = false;
		}

		SetPos(pos);
	}
}

void ya::BasedObject::Render(HDC hdc)
{
	GameObject::Render(hdc);

	Vector2 pos = GetPos();
	Vector2 scale = GetScale();

	Vector2 finalPos;
	finalPos.x = (pos.x - mImage->GetWidth() * (scale.x / 2.0f));
	finalPos.y = (pos.y - mImage->GetHeight() * (scale.y / 2.0f));

	Vector2 rect;
	rect.x = mImage->GetWidth() * scale.x;
	rect.y = mImage->GetHeight() * scale.y;

	finalPos = Camera::CalculatePos(finalPos);

	//TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
	//	, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
	//	, RGB(255, 0, 255));
}

void ya::BasedObject::OnCollisionEnter(Collider* other)
{
}

void ya::BasedObject::OnCollisionStay(Collider* other)
{
}

void ya::BasedObject::OnCollisionExit(Collider* other)
{
}

void ya::BasedObject::Move(eDir _dir, bool pushed)
{
}
