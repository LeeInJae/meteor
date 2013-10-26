#pragma once
#include "gameobject.h"

class CSkill :
	public CGameObject
{
public:
	CSkill(void);
	~CSkill(void);

	int getDamage() { return m_Damage; };
	int getDuration() { return m_Duration; };

protected:
	int m_Damage; // 데미지
	int m_Duration; // 지속 시간
	CGameObject & m_Target; // 타겟
};

