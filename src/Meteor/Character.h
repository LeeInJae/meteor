//@author : ���ͼ� (2013.10.23)

#pragma once

#include "GameObject.h"
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

// �� ĳ���͵�(PC,NPC,MOB)
class CCharacter :
	public CGameObject
{
public:
	CCharacter(void);
	virtual ~CCharacter(void);

	bool HitCheck(CSkill &skill);
	bool ApplyDamage(int damage);
	bool SetBuff(CSkill &);
	int GetHp() { return m_Hp; }
	bool IsDead() { return (m_Hp <= 0); }
	void SetStatus( CharacterStatus status ) { m_Status = status; }

protected:
	int m_Hp;
	int m_Speed;

	CharacterStatus m_Status;
	std::list<CSkill*> m_Buff; // ĳ���Ϳ� �ɸ� ������ ��ų ����Ʈ
};