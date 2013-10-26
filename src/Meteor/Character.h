#pragma once
#include "gameobject.h"
#include "stdafx.h"
#include <forward_list>
#include "Skill.h"

enum CharacterStatus {
	DEAD,
	STAND,
	WALK,
	RUN,
	ATTACK,
	CASTING,
	DEFENCE,
	AVOID,
	STUN
};

class CCharacter :
	public CGameObject
{
public:
	CCharacter(void);
	virtual ~CCharacter(void);

	bool HitCheck(int x, int y, CSkill &skill);
	bool ApplyDamage(int damage);
	bool SetBuff(CSkill &);
	bool GetHp();

protected:
	int m_HP;
	int m_Speed;

	CharacterStatus m_Status;
	std::forward_list<CSkill&> m_Buff;

};

