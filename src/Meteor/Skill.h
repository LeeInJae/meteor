//@author : 조익성 (2013.10.25)

#pragma once

#include "GameObject.h"

// 스킬
class CSkill : public CGameObject
{
public:
	CSkill() {};
	virtual ~CSkill() {};

	int GetDamage() { return m_Damage; };
	int GetDuration() { return m_Duration; };
	virtual void ApplySkill( CGameObject * target ) = 0;

protected:
	int m_Damage; // 데미지
	int m_Duration; // 지속 시간
	CGameObject * m_Target; // 타겟
};

