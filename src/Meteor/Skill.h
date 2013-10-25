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
	int m_Damage; // 데미지
	int m_Duration; // 지속 시간
	SkillType m_SkillType; // 스킬 종류
};

