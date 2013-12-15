#pragma once

#include "Skill.h"

class CMonsterAttack : public CSkill
{
public:
	CMonsterAttack(void);
	virtual ~CMonsterAttack(void);

	bool Update( float deltaTime ) override;
	void Render( const Position & cameraPosition ) override;

	void ApplySkill( CGameObject * target ) override;
	bool HitCheck( CGameObject * target ) override;
};

