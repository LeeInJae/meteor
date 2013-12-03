//@author : ���ͼ� (2013.10.23)

#pragma once

#include "Character.h"

// �÷��̾�
class CPC : public CCharacter
{
public:
	CPC(void);
	~CPC(void);

	bool Update( float deltaTime ) override;

	bool LoadAnimation();
	CAnimation * GetAnimation() const;

	//std::vector<int> & GetCasting() { return m_Casting; }
	std::list<std::string> & GetCasting() { return m_Casting; }
	//bool Cast( int id );
	bool Cast( std::string id );
	bool Action();

private:
	//std::vector<int>	m_Casting;
	CSkill *			m_BasicAttack;
	std::list<std::string> m_Casting;
};

