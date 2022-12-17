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
		static bool m_IsPushable;//�м��ִ� ��ü�ΰ� 
		static bool m_IsMoveable;//���۰����� ��ü�ΰ�
		static bool m_IsStop;//�����ϼ����� ��ü�ΰ�

		int m_movecnt;

		std::vector<std::wstring> AnimName;
    };
}


