//@author : 조익성 (2013.10.23)

#pragma once

#include "Character.h"

// 플레이어
class CPC : public CCharacter
{
public:
	CPC(void);
	~CPC(void);

	bool Update( float deltaTime ) override;

	bool LoadAnimation();
	CAnimation * GetAnimation() const;

	std::vector<int> & GetCasting() { return m_Casting; }
	bool Cast( int id );
	bool Action();

private:
	std::vector<int>	m_Casting;
};

