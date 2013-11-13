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
	if( m_Fps == 0 )
		return true;

	m_ElapsedTime += deltaTime;

	if( m_ElapsedTime >= float( 1.0f / m_Fps ) )
	{
		++m_FrameNumber;
		m_ElapsedTime = 0;
	}
	
	if( m_FrameNumber >= m_Sprites.size() )
		m_FrameNumber = 0;

	return true;
}

// ----------------------------------------------------------------
//	Render
// ----------------------------------------------------------------
void CAnimation::Render()
{
	CSprite * sprite;

	if( m_Fps == 0 )
		sprite = m_Sprites[0];
	else
		sprite = m_Sprites[m_FrameNumber];

	sprite->SetPosition( m_Position );
	sprite->Render();
}
