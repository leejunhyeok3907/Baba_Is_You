#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Animator;

	class BasedObject : public GameObject
	{
	public:
		BasedObject();
		~BasedObject();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

	public:
		virtual bool IsPushable() PURE;
		virtual bool IsMoveAble() PURE;
		virtual bool IsStop() PURE;

	public:
		virtual void Move(eDir _dir, bool pushed = false) PURE;
		void SetMapPos(Vector2 _v) { map_pos = _v; }
		Vector2 GetMapPos() { return map_pos; }

	protected:
		Vector2 mDest;
		float mSpeed;
		Image* mImage;
		Animator* mAnimator;
		Vector2 map_pos;

		bool m_MoveOnce;
	};
}

