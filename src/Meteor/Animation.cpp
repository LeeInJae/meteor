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
	, m_Stop(true)
	, m_Loop(true)
	, m_ElapsedTime( 0 )
	, m_Rotation ( 0.0f )
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
void CAnimation::SetPosition( const Position & position, const Position & cameraPosition )
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

	if( m_Stop || m_Fps == 0 )
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
void CAnimation::Render() const
{
	CSprite * sprite = m_Sprites[ m_FrameNumber ];

	sprite->SetPosition( m_Position );
	sprite->SetRotation( m_Rotation );
	sprite->Render();
}


// ----------------------------------------------------------------
//	Play
// ----------------------------------------------------------------
void CAnimation::Play( int frameNumber, bool loop )
{
	m_FrameNumber = frameNumber;
	m_Stop = false;
	m_Loop = loop;
}

void CAnimation::Play( bool loop )
{
	m_Stop = false;
	m_Loop = loop;
}


// ----------------------------------------------------------------
//	Stop
// ----------------------------------------------------------------
void CAnimation::Stop( int frameNumber )
{
	m_FrameNumber = frameNumber;
}

void CAnimation::Stop()
{
}
