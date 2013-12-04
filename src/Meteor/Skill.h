//@author : 조익성 (2013.10.25)

#pragma once

#include "GameObject.h"
#include "AnimationInfo.h"

// 스킬
class CSkill : public CGameObject
{
public:
	CSkill(void) {};
	virtual ~CSkill() {};

	int						GetDamage()			{ return m_Damage; };
	float					GetDuration()		{ return m_Duration; };
	virtual bool			LoadAnimation();
	virtual CAnimation *	GetAnimation() const;
	virtual void			ApplySkill( CGameObject * target ) = 0;

protected:
	int						m_Damage;		// 데미지
	float					m_Duration;		// 지속 시간
	CGameObject *			m_Target;		// 타겟
	ResourceId				m_SkillName;
};
