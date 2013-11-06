#include "stdafx.h"
#include "PC.h"

#define WALK_SPEED 128

CPC::CPC(void)
{
}

CPC::~CPC(void)
{
	for ( auto animation : m_Animation )
		delete animation;
	m_Animation.clear();
}

bool CPC::LoadAnimation()
{
	CAnimation * animation;

	animation = new CAnimation( "CHARACTOR_WALK_LEFT" );
	animation->SetSpeed( 8 );
	if( animation->LoadSprite() )
		m_Animation.push_back( animation );

	animation = new CAnimation( "CHARACTOR_WALK_RIGHT" );
	animation->SetSpeed( 8 );
	if( animation->LoadSprite() )
		m_Animation.push_back( animation );

	animation = new CAnimation( "CHARACTOR_WALK_UP" );
	animation->SetSpeed( 8 );
	if( animation->LoadSprite() )
		m_Animation.push_back( animation );

	animation = new CAnimation( "CHARACTOR_WALK_DOWN" );
	animation->SetSpeed( 8 );
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
	CAnimation * animation = m_Animation[3];

	switch( m_Direction )
	{
	case LEFT:
		animation = m_Animation[0];
		break;

	case RIGHT:
		animation = m_Animation[1];
		break;

	case UP:
		animation = m_Animation[2];
		break;

	case DOWN:
		animation = m_Animation[3];
		break;
	}

	if ( m_Status == WALK )
		animation->SetSpeed( 8 );
	else if ( m_Status == STAND )
		animation->SetSpeed( 0 );

	return animation;
}
