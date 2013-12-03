#include "stdafx.h"
#include "Character.h"

const static float SQRT2_2 = 0.70710678118f;

CCharacter::CCharacter(void)
	: m_ActionTime(0.0f)
	, m_Skill(nullptr)
	, m_Status(CHARACTER_STAND)
{
}

CCharacter::~CCharacter(void)
{
}


bool CCharacter::Update( float deltaTime )
{
	if ( m_ActionTime > 0.0f )
		m_ActionTime -= deltaTime;
	else
		m_Skill = nullptr;

	if ( m_Skill )
	{
		m_Skill->Update( deltaTime );
	}

	return CGameObject::Update( deltaTime );
}


void CCharacter::Render( Position & cameraPosition )
{
	CGameObject::Render( cameraPosition );
	if ( m_Skill )
		m_Skill->Render( cameraPosition );
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
	float diagonal = distance * SQRT2_2;

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

//bool CCharacter::Action()
//{
//	if( m_ActionTime > 0.0f )
//		return false;
//
//	m_Status = CHARACTER_ATTACK;
//	m_ActionTime = 0.7f;
//
//	m_Skill = m_BasicAttack;
//	m_Skill->ApplySkill( this );
//
//	GetAnimation()->Stop( true );
//
//	return true;
//}
bool CCharacter::Action()
{
	return false;
}

void CCharacter::SetStatus( CharacterStatus status )
{
	if( m_ActionTime > 0.0f )
		return;
	m_Status = status;
}

void CCharacter::SetDirection( Direction direction )
{
	if( m_ActionTime > 0.0f )
		return;
	m_Direction = direction;
}
