#pragma once

#include "Skill.h"

class CBasicAttack : public CSkill
{
public:
	CBasicAttack();
	virtual ~CBasicAttack();

	bool Update( float deltaTime ) override;

	void ApplySkill( CGameObject * target ) override;
	bool HitCheck( CGameObject * target ) override;
};

