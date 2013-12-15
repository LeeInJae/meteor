//@author : ���ͼ� (2013.10.23)

#pragma once

#include "Character.h"

// ����
class CMonster :
	public CCharacter
{
public:
	CMonster( ResourceId monsterId );
	~CMonster(void);

	bool LoadAnimation();

	// --------------------------------
	//	CCharacter
	// --------------------------------
	bool Action() override;

	// --------------------------------
	//	CGameObject
	// --------------------------------
	bool Update( float deltaTime ) override;
	CAnimation * GetAnimation() const override;

private:
	ResourceId	m_MonsterId;
};

