#include "yaPlayer.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaMissile.h"
#include "yaScene.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaCamera.h"
#include "yaBackPack.h"
#include "yaRigidbody.h"
#include "yaUIManager.h"

namespace ya
{
	Player::Player()
		: mSpeed(1.0f)
		, mHp(100)
	{
		SetName(L"Player");
		SetPos({ 500.0f, 100.0f });
		SetScale({ 1.0f, 1.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\link.bmp");
		}
		
		mAnimator = new Animator();
		//mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\Idle"
		//	, L"PlaneIdle");


		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 3, 0.1f);

		mAnimator->CreateAnimation(L"MoveDown", mImage
			, Vector2(0.0f, 520.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 10, 0.1f);
		mAnimator->CreateAnimation(L"MoveLeft", mImage
			, Vector2(0.0f, 650.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 10, 0.1f);
		mAnimator->CreateAnimation(L"MoveUp", mImage
			, Vector2(0.0f, 780.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 10, 0.1f);
		mAnimator->CreateAnimation(L"MoveRight", mImage
			, Vector2(0.0f, 910.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 10, 0.1f);

		mAnimator->Play(L"Idle", true);
		//mAnimator->Find
		// 
		// s(L"MoveRight")->mCompleteEvent = std::bind(&Player::WalkComplete, this);
		//mAnimator->GetCompleteEvent(L"MoveRight") = std::bind(&Player::WalkComplete, this);

		//mAnimator->Play(L"MoveRight", true);
		//mAnimator->mCompleteEvent = std::bind(&Player::WalkComplete, this);
		AddComponent(mAnimator);

		Collider* coliider = new Collider();
		AddComponent(coliider);

		coliider->SetOffset(Vector2(0.0f, 50.0f));
		coliider->SetScale(Vector2(10.0f, 10.0f));

		Collider* coliider2 = new Collider();
		AddComponent(coliider2);

		coliider2->SetOffset(Vector2(60.0f, 0.0f));
		coliider2->SetScale(Vector2(10.0f, 10.0f));

		//Rigidbody* rigidBody = new Rigidbody();
		//AddComponent(rigidBody);

		AddComponent<Rigidbody>();



		mCoff = 0.1f;
		mMisiileDir = Vector2::One;
	}

	Player::~Player()
	{

	}

	void Player::Tick()
	{
		GameObject::Tick();
		

		if (KEY_DOWN(eKeyCode::W))
		{
			mAnimator->Play(L"MoveUp", true);

			Vector2 pos = GetPos();
			dest = Vector2(pos.x, pos.y - 200.f);
		}
		if (KEY_DOWN(eKeyCode::S))
		{
			mAnimator->Play(L"MoveDown", true);

			Vector2 pos = GetPos();
			dest = Vector2(pos.x, pos.y + 200.f);
		}
		if (KEY_DOWN(eKeyCode::A))
		{
			Vector2 pos = GetPos();
			dest = Vector2(pos.x - 200.f, pos.y);

			mAnimator->Play(L"MoveLeft", true);
		}
		if (KEY_DOWN(eKeyCode::D))
		{
			mAnimator->Play(L"MoveRight", true);

			Vector2 pos = GetPos();
			dest = Vector2(pos.x + 200.f, pos.y);
		}

		if (KEY_UP(eKeyCode::W))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::S))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::A))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::D))
		{
			mAnimator->Play(L"Idle", true);
		}

		if (KEY_PREESE(eKeyCode::W) || KEY_PREESE(eKeyCode::S) || KEY_PREESE(eKeyCode::A) || KEY_PREESE(eKeyCode::D))
		{
			Vector2 pos = GetPos();

			pos = math::lerp(pos, dest, 0.003f);

			float value = (pos - dest).Length();
			if (value < 10.0f) pos = dest;

			SetPos(pos);
		}
		
		if (KEY_PREESE(eKeyCode::W))
		{
			//pos.y -= 120.0f * Time::DeltaTime();
			//missile->mDir.y = -1.0f;

			//GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -200.0f));
		}
		else if (KEY_PREESE(eKeyCode::S))
		{
			//pos.y += 120.0f * Time::DeltaTime();
			//GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, 200.0f));
		}
		else if (KEY_PREESE(eKeyCode::A))
		{
			//pos.x -= 120.0f * Time::DeltaTime();
			//missile->mDir.x = 1.0f;
			
			//GetComponent<Rigidbody>()->AddForce(Vector2(-200.0f, 0.0f));
		}
		else if (KEY_PREESE(eKeyCode::D))
		{
			//pos.x += 120.0f * Time::DeltaTime();
			//GetComponent<Rigidbody>()->AddForce(Vector2(200.0f, 0.0f));
		}

		if (KEY_DOWN(eKeyCode::SPACE))
		{
			Rigidbody* rigidbody = GetComponent<Rigidbody>();
			Vector2 velocity = rigidbody->GetVelocity();
			velocity.y = -500.0f;
			rigidbody->SetVelocity(velocity);

			rigidbody->SetGround(false);

			UIManager::Pop(eUIType::OPTION);
		}
	}

	void Player::Render(HDC hdc)
	{
		//HBRUSH blueBrush = CreateSolidBrush(RGB(153, 204, 255));
		//Brush brush(hdc, blueBrush);

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//Pen pen(hdc, redPen);





		GameObject::Render(hdc);
	}

	void Player::OnCollisionEnter(Collider* other)
	{
	}

	void Player::OnCollisionStay(Collider* other)
	{

	}

	void Player::OnCollisionExit(Collider* other)
	{

	}

	void Player::WalkComplete()
	{
		Missile* missile = new Missile();

		Scene* playScene = SceneManager::GetPlayScene();
		playScene->AddGameObject(missile, eColliderLayer::Player_Projecttile);

		Vector2 playerPos = GetPos();
		Vector2 playerScale = GetScale() / 2.0f;
		Vector2 missileScale = missile->GetScale();

		missile->SetPos((playerPos + playerScale) - (missileScale / 2.0f));
	}
}
