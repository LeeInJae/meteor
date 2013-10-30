#include "stdafx.h"
#include "PC.h"

#define WALK_SPEED 128

CPC::CPC(void)
{
}

CPC::~CPC(void)
{
}

bool CPC::LoadAnimation()
{
	CAnimation * animation;

	animation = new CAnimation( "CHARACTOR_WALK_LEFT", 5 );
	if( animation->LoadSprite() )
		m_Animation.push_back( animation );

	animation = new CAnimation( "CHARACTOR_WALK_LEFT", 5 );
	if( animation->LoadSprite() )
		m_Animation.push_back( animation );

	animation = new CAnimation( "CHARACTOR_WALK_RIGHT", 5 );
	if( animation->LoadSprite() )
		m_Animation.push_back( animation );

	animation = new CAnimation( "CHARACTOR_WALK_UP", 5 );
	if( animation->LoadSprite() )
		m_Animation.push_back( animation );

	animation = new CAnimation( "CHARACTOR_WALK_DOWN" );
	if( animation->LoadSprite() )
		m_Animation.push_back( animation );

	return true;
}

bool CPC::Update( float deltaTime )
{
	CGameObject::Update( deltaTime );

	if ( m_Status == WALK )
	{
		switch( m_Direction )
		{
		case LEFT:
			Move( ( int )( ( -WALK_SPEED ) * deltaTime * 0.001f ), 0 );
			break;

		case RIGHT:
			Move( ( int )( ( WALK_SPEED ) * deltaTime * 0.001f ), 0 );
			break;

		case UP:
			Move( 0, ( int )( ( -WALK_SPEED ) * deltaTime * 0.001f ) );
			break;

		case DOWN:
			Move( 0, ( int )( ( WALK_SPEED ) * deltaTime * 0.001f ) );
			break;

		default:
			break;
		}
	}

	return true;
}

CAnimation * CPC::GetAnimation() const
{
	if ( m_Status == WALK )
	{
		switch( m_Direction )
		{
		case LEFT:
			return m_Animation[1];

		case RIGHT:
			return m_Animation[2];

		case UP:
			return m_Animation[3];

		case DOWN:
			return m_Animation[4];
		}
	}

	return m_Animation[0];
}
