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
	std::list<std::string> &	GetCasting() { return m_Casting; }
	bool						Cast( std::string id );
	float						GetCoolTime( std::string gem ) { return m_CoolTime[gem]; }

	// --------------------------------
	//	CCharacter
	// --------------------------------
	bool Action() override;
	bool Update( float deltaTime ) override;

	// --------------------------------
	//	CGameObject
	// --------------------------------
	CAnimation * GetAnimation() const override;

	// --------------------------------
	//	IEventListener
	// --------------------------------
	void EventHandler( CGameObject * event ) override;

private:
	std::list<std::string>				m_Casting;
	std::map< std::string, CSkill * >	m_SkillTable;
	std::map< std::string, float >		m_CoolTime;
};

