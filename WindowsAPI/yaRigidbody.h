#pragma once
#include "yaComponent.h"

namespace ya
{
	class Rigidbody : public Component
	{
	public:
		Rigidbody(bool haveGravity = true);
		~Rigidbody();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void AddForce(Vector2 force);
		void SetMass(float mass) { mMass = mass; }
		void SetGround(bool isGround) { mbGround = isGround; }
		Vector2 GetVelocity() { return mVelocity; }
		void SetVelocity(Vector2 velocity) { mVelocity = velocity; }

	private:
		// ���� �������� �̿��� �̵�
		float mMass;
		float mFriction;
		//float mMoveFriction;
		Vector2 mForce;
		Vector2 mVelocity;
		Vector2 mAccelation;

		// �߷� �̿��� ����
		Vector2 mGravity;
		bool mbGround;
		bool m_IsGravity;
		Vector2 mLimitVelocity;
	};
}