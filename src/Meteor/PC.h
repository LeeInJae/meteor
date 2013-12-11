//@author : 조익성 (2013.10.23)

#pragma once

#include "Character.h"

// 플레이어
class CPC : public CCharacter
{
public:
	CPC(void);
	~CPC(void);

	bool LoadAnimation();
	CAnimation * GetAnimation() const;

	//std::vector<int> & GetCasting() { return m_Casting; }
	std::list<std::string> & GetCasting() { return m_Casting; }
	//bool Cast( int id );
	bool Cast( std::string id );
	bool Action();

private:
	CSkill *							m_BasicAttack;
	std::list<std::string>				m_Casting;
	std::map< std::string, CSkill * >	m_SkillTable;
};

