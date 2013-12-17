//@author : 조익성 (2013.10.25)

#pragma once

#include "GameObject.h"
#include "AnimationInfo.h"

// 스킬
class CSkill : public CGameObject
{
public:
	CSkill() {};
	virtual ~CSkill() {};

	float					GetDamage()			{ return m_Damage; };
	float					GetDuration()		{ return m_Duration; };
	virtual bool			LoadAnimation();
	virtual CAnimation *	GetAnimation() const;
	virtual void			ApplySkill( CGameObject * target ) = 0;
	virtual bool			HitCheck( CGameObject * target ) = 0;

	// --------------------------------
	//	CGameObject
	// --------------------------------
	bool Move( float x, float y ) override;
	bool Move( Direction direction, float distance ) override { return CGameObject::Move( direction, distance ); };

protected:
	float					m_Damage;		// 데미지
	float					m_Duration;		// 지속 시간
	CGameObject *			m_Target;		// 타겟
	ResourceId				m_SkillName;
};
