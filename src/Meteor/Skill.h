//@author : ���ͼ� (2013.10.25)

#pragma once
#include "gameobject.h"

// ��ų
class CSkill :
	public CGameObject
{
public:
	CSkill(void);
	~CSkill(void);

	int GetDamage() { return m_Damage; };
	int GetDuration() { return m_Duration; };
	void ApplySkill( CGameObject &target );

protected:
	int m_Damage; // ������
	int m_Duration; // ���� �ð�
	CGameObject * m_Target; // Ÿ��
};

