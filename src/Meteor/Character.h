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

	bool HitCheck(int x1, int y1, int x2, int y2, CSkill &skill); // �� ��ǥ ������ ����(��ų����)�� ������ üũ
	bool ApplyDamage(int damage);
	bool SetBuff(CSkill &);
	bool GetHp() { return m_HP;};

protected:
	int m_HP;
	int m_Speed;

	CharacterStatus m_Status;
	std::forward_list<CSkill&> m_Buff; // ĳ���Ϳ� �ɸ� ������ ��ų ����Ʈ

};

