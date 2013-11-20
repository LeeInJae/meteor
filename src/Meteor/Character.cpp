#include "stdafx.h"
#include "Character.h"

const static float SQRT_HALF2 = 0.70710678118f;

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

bool CCharacter::Walk( Direction direction, float distance )
{
	float diagonal = distance * SQRT_HALF2;

	switch( m_Direction )
	{
	case LEFT:
		return Move( -distance, 0 );

	case RIGHT:
		return Move( distance, 0 );

	case UP:
		return Move( 0, -distance );

	case DOWN:
		return Move( 0, distance );

	case UP_LEFT:
		return Move( -diagonal, -diagonal );

	case UP_RIGHT:
		return Move( diagonal, -diagonal );

	case DOWN_LEFT:
		return Move( -diagonal, diagonal );

	case DOWN_RIGHT:
		return Move( diagonal, diagonal );
	}

	return false;
}
