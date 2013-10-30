#include "stdafx.h"
#include "Character.h"


CCharacter::CCharacter(void)
{
}


CCharacter::~CCharacter(void)
{
}

bool CCharacter::HitCheck(int x1, int y1, int x2, int y2, CSkill &skill)
{
	if(m_X > x1 && m_X < x2 && m_Y > y1 && m_Y < y2)
		return true;
	else
		return false;
}