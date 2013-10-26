#pragma once
#include "gameobject.h"

class CSkill :
	public CGameObject
{
public:
	CSkill(void);
	~CSkill(void);

	int getDamage() { return m_Damage; };
	int getDuration() { return m_Duration; };

protected:
	int m_Damage; // ������
	int m_Duration; // ���� �ð�
	CGameObject & m_Target; // Ÿ��
};

