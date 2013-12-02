#pragma once

#include "Skill.h"
#include "AnimationInfo.h"

class CBasicAttack : public CSkill
{
public:
	CBasicAttack();
	virtual ~CBasicAttack();

	bool Update( float deltaTime ) override;
	bool LoadAnimation();
	CAnimation * GetAnimation() const;

	void ApplySkill( CGameObject * target ) override;
};

