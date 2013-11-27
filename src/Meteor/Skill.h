//@author : 조익성 (2013.10.25)

#pragma once
#include "gameobject.h"

// 스킬
class CSkill :
	public CGameObject
{
public:
	CSkill(void);
	~CSkill(void);

	int GetDamage() { return m_Damage; };
	int GetDuration() { return m_Duration; };
	void ApplySkill( CGameObject &target );

protected:
	int m_Damage; // 데미지
	int m_Duration; // 지속 시간
	CGameObject * m_Target; // 타겟
};

