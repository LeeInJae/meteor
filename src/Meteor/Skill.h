#pragma once
#include "gameobject.h"

enum SkillType {
	ATTACK,
	HEAL,
	BUFF,
	DOT,
};

class CSkill :
	public CGameObject
{
public:
	CSkill(void);
	~CSkill(void);

	int getDamage();
	int getDuration();
	SkillType getSkillType();

protected:
	int m_Damage; // ������
	int m_Duration; // ���� �ð�
	SkillType m_SkillType; // ��ų ����
};

