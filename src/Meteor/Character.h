#pragma once
#include "gameobject.h"
#include "stdafx.h"
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

	bool HitCheck(CSkill &skill);
	bool ApplyDamage(int damage);
	bool SetBuff(CSkill &);
	bool GetHp() { return m_Hp;};
	bool IsDead() { return (m_Hp <= 0);};

protected:
	int m_Hp;
	int m_Speed;

	CharacterStatus m_Status;
	std::forward_list<CSkill&> m_Buff; // ĳ���Ϳ� �ɸ� ������ ��ų ����Ʈ

};

