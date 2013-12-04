//@author : ���ͼ� (2013.10.25)

#pragma once

#include "GameObject.h"
#include "AnimationInfo.h"

// ��ų
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
	int						m_Damage;		// ������
	float					m_Duration;		// ���� �ð�
	CGameObject *			m_Target;		// Ÿ��
	ResourceId				m_SkillName;
};
