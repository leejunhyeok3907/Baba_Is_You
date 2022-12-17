#pragma once
#include "BasedObject.h"

namespace ya 
{
    class Baba :
        public BasedObject
    {
	public:
		Baba();
		~Baba();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	public:
		virtual void Move(eDir _dir, bool pushed = false);
		virtual bool IsPushable() { return m_IsPushable; }
		virtual bool IsMoveAble() { return m_IsMoveable; }
		virtual bool IsStop() { return m_IsStop; }

		static void SetPushable(bool _check) { m_IsPushable = _check; }
		static void SetMoveable(bool _check) { m_IsMoveable = _check; }
		static void SetStop(bool _check) { m_IsStop = _check; }

	private:
		static bool m_IsPushable;//밀수있는 객체인가 
		static bool m_IsMoveable;//조작가능한 객체인가
		static bool m_IsStop;//움직일수없는 객체인가

		int m_movecnt;

		std::vector<std::wstring> AnimName;
    };
}


