//@author : 조익성 (2013.10.23)

#pragma once

#include "GameObject.h"
#include "Skill.h"

enum CharacterStatus {
	CHARACTER_DEAD,
	CHARACTER_STAND,
	CHARACTER_WALK,
	CHARACTER_RUN,
	CHARACTER_ATTACK,
	CHARACTER_CASTING,
	CHARACTER_DEFENCE,
	CHARACTER_AVOID,
	CHARACTER_STUN,
};

// 각 캐릭터들(PC,NPC,MOB)
class CCharacter :
	public CGameObject
{
public:
	CCharacter(void);
	virtual ~CCharacter(void);

	virtual bool Update( float deltaTime ) override;
	virtual void Render( Position & cameraPosition ) override;

	bool HitCheck(CSkill &skill);
	bool ApplyDamage(int damage);
	bool SetBuff(CSkill &);
	int GetHp() { return m_Hp; }
	bool IsDead() { return (m_Hp <= 0); }
	void SetStatus( CharacterStatus status );
	void SetDirection( Direction direction );
	
	// Override
	virtual bool Move( float x, float y ) override;
	virtual bool Walk( Direction direction, float speed );
	virtual bool Action();

protected:
	int m_Hp;
	int m_Speed;
	float m_ActionTime;

	CharacterStatus		m_Status;
	CSkill *			m_BasicAttack;
	CSkill *			m_Skill;
	std::list<CSkill*>	m_Buff; // 캐릭터에 걸린 버프형 스킬 리스트
};
