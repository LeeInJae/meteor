//@author : 조익성 (2013.10.23)

#pragma once

#include "GameObject.h"
#include "Skill.h"

class CHpUI;

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
	virtual void Render( const Position & cameraPosition ) override;

	bool	HitCheck(CSkill &skill);
	bool	ApplyDamage(int damage);
	bool	SetBuff(CSkill &);
	void	SetStatus( CharacterStatus status );
	void	SetDirection( Direction direction );

	void	SetHp( float hp )		{ m_Hp = hp; }
	void	SetMaxHp( float hp )	{ m_MaxHp = hp; }
	float	GetHp() const			{ return m_Hp; }
	float	GetMaxHp() const		{ return m_MaxHp; }
	bool	IsDead() const			{ return (m_Hp <= 0.0f); }

	// Override
	virtual bool Move( float x, float y ) override;
	virtual bool Walk( Direction direction, float speed );
	virtual bool Action();

protected:
	float	m_Hp;
	float	m_MaxHp;
	int		m_Speed;
	float	m_ActionTime;

	CharacterStatus		m_Status;
	CHpUI *				m_HpUI;
	CSkill *			m_Skill;
	std::list<CSkill*>	m_Buff; // 캐릭터에 걸린 버프형 스킬 리스트
};
