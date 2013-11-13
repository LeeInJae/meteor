//@author : 조익성 (2013.10.23)

#pragma once

#include "Character.h"

// 몬스터
class CMonster :
	public CCharacter
{
public:
	CMonster( std::wstring monsterId );
	~CMonster(void);

	bool LoadAnimation();
	bool Update( float deltaTime, Position & playerPosition );
	CAnimation * GetAnimation() const;

private:
	std::wstring	m_MonsterId;
};

