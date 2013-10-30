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

	bool HitCheck(CSkill &skill); // 두 좌표 사이의 영역(스킬범위)에 들어가는지 체크
	bool ApplyDamage(int damage);
	bool SetBuff(CSkill &);
	bool GetHp() { return m_Hp;};
	bool IsDead() { return (m_Hp <= 0);};

protected:
	int m_Hp;
	int m_Speed;

	CharacterStatus m_Status;
	std::forward_list<CSkill&> m_Buff; // 캐릭터에 걸린 버프형 스킬 리스트

};

