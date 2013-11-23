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
	bool Update( float deltaTime, Position & playerPosition );
	CAnimation * GetAnimation() const;

private:
	ResourceId	m_MonsterId;
};

