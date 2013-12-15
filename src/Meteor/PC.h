//@author : ���ͼ� (2013.10.23)

#pragma once

#include "Character.h"

// �÷��̾�
class CPC : public CCharacter
{
public:
	CPC(void);
	~CPC(void);

	bool LoadAnimation();
	std::list<std::string> &	GetCasting() { return m_Casting; }
	bool						Cast( std::string id );

	// --------------------------------
	//	CCharacter
	// --------------------------------
	bool Action() override;

	// --------------------------------
	//	CGameObject
	// --------------------------------
	CAnimation * GetAnimation() const override;

private:
	std::list<std::string>				m_Casting;
	std::map< std::string, CSkill * >	m_SkillTable;
};

