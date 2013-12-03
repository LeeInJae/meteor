#pragma once
#include "skill.h"
class CFlameSlash :
	public CSkill
{
public:
	CFlameSlash(void);
	~CFlameSlash(void);

	bool LoadAnimation() override;
	CAnimation * GetAnimation() const override;

	bool Update( float deltaTime ) override;
	void ApplySkill( CGameObject * target ) override;
};

