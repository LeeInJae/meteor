#include "stdafx.h"
#include "Animation.h"
#include "Sprite.h"
#include "ResourceManager.h"

// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CAnimation::CAnimation()
	: m_FrameNumber( 0 )
	, m_FpsNumber( 0 )
	, m_ElapsedTime( 0 )
{
}

// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
CAnimation::~CAnimation()
{
	Release();
}

// ----------------------------------------------------------------
//	SetSpeed
// ----------------------------------------------------------------
void CAnimation::SetSpeed( int fps )
{
	m_FpsNumber = fps;
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
	if( m_FpsNumber == 0 )
		return true;

	m_ElapsedTime += deltaTime;

	if( m_ElapsedTime >= float( 1000.0f / m_FpsNumber ) )
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
	if( m_FpsNumber == 0 )
		m_Sprites[0]->Render();
	else
		m_Sprites[m_FrameNumber]->Render();
}

// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CAnimation::Release()
{
	for ( auto sprite : m_Sprites )
		sprite->Release();
	m_Sprites.clear();

	CResourceManager::GetInstance().ReleaseResource(this);
}
