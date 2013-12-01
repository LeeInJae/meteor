#include "stdafx.h"
#include "Animation.h"
#include "Sprite.h"
#include "ResourceManager.h"

// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CAnimation::CAnimation()
	: m_FrameNumber( 0 )
	, m_Fps( 0 )
	, m_Loop(true)
	, m_ElapsedTime( 0 )
{
}

// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
CAnimation::~CAnimation()
{
}


// ----------------------------------------------------------------
//	SetPosition
// ----------------------------------------------------------------
void CAnimation::SetPosition( Position & position, Position & cameraPosition )
{
	m_Position = position;
	m_Position.x -= cameraPosition.x;
	m_Position.y -= cameraPosition.y;
}


// ----------------------------------------------------------------
//	LoadSprite
// ----------------------------------------------------------------
void CAnimation::AddSprite( CSprite * sprite )
{
	m_Sprites.push_back( sprite );
}


// ----------------------------------------------------------------
//	Update
// ----------------------------------------------------------------
bool CAnimation::Update( float deltaTime )
{
	assert( m_Sprites.size() > 0 );

	if( m_Fps == 0 )
		return false;

	m_ElapsedTime += deltaTime;

	if( m_ElapsedTime >= static_cast<float>( 1.0f / m_Fps ) )
	{
		++ m_FrameNumber;
		m_ElapsedTime = 0;
	}
	
	if( m_FrameNumber >= m_Sprites.size() )
	{
		if ( m_Loop )
			m_FrameNumber = 0;
		else
		{
			-- m_FrameNumber;
			m_Fps = 0;
		}
	}

	return true;
}


// ----------------------------------------------------------------
//	Render
// ----------------------------------------------------------------
void CAnimation::Render()
{
	CSprite * sprite = m_Sprites[ m_FrameNumber ];

	sprite->SetPosition( m_Position );
	sprite->Render();
}


// ----------------------------------------------------------------
//	Play
// ----------------------------------------------------------------
void CAnimation::Play( int fps, bool loop )
{
	m_Fps = fps;
	m_Loop = loop;
}


// ----------------------------------------------------------------
//	Stop
// ----------------------------------------------------------------
void CAnimation::Stop( bool reset )
{
	m_Fps = 0;
	if ( reset )
		m_FrameNumber = 0;
}
