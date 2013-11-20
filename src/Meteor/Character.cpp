#include "stdafx.h"
#include "Character.h"

CCharacter::CCharacter(void)
	: m_Status(CHARACTER_STAND)
{
}

CCharacter::~CCharacter(void)
{
}

bool CCharacter::HitCheck(CSkill &skill)
{
	return false;
}

bool CCharacter::Move( float x, float y )
{
	if ( CGameObject::Move( x, y ) )
		return true;

	m_Status = CHARACTER_STAND;
	return false;
}
