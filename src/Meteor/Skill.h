//@author : ���ͼ� (2013.10.25)

#pragma once

#include "GameObject.h"

// ��ų
class CSkill : public CGameObject
{
public:
	CSkill() {};
	virtual ~CSkill() {};

	int GetDamage() { return m_Damage; };
	int GetDuration() { return m_Duration; };
	virtual void ApplySkill( CGameObject * target ) = 0;

protected:
	int m_Damage; // ������
	int m_Duration; // ���� �ð�
	CGameObject * m_Target; // Ÿ��
};

