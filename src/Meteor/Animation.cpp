#include "stdafx.h"
#include "Animation.h"
#include "Sprite.h"


// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CAnimation::CAnimation( std::string key )
	: m_AnimationKey( key )
	, m_FrameNumber( 0 )
	, m_FpsNumber( 10 )
	, m_ElapsedTime( 0 )
{
}

CAnimation::CAnimation( std::string key, int fpsNumber )
	: m_AnimationKey( key )
	, m_FrameNumber( 0 )
	, m_FpsNumber( fpsNumber )
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
//	Update
// ----------------------------------------------------------------
bool CAnimation::Update( float deltaTime )
{
	m_ElapsedTime += deltaTime;

	if( m_ElapsedTime >= float( 0.001 * m_FpsNumber ) )
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
bool CAnimation::Render()
{
	m_Sprites[m_FrameNumber]->Render();

	return true;
}

bool CAnimation::LoadSprite()
{
	// TODO:
	//	vector<Sprite &> sprites = ResourceManager::GetInstance().GetSprite( m_AnimationKey );

	if( m_AnimationKey == "CHARACTOR_WALK_LEFT" )
	{
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_LEFT_01.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_LEFT_02.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_LEFT_03.png" ) );
	}

	if( m_AnimationKey == "CHARACTOR_WALK_RIGHT" )
	{
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_RIGHT_01.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_RIGHT_02.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_RIGHT_03.png" ) );
	}

	if( m_AnimationKey == "CHARACTOR_WALK_UP" )
	{
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_UP_01.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_UP_02.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_UP_03.png" ) );
	}

	if( m_AnimationKey == "CHARACTOR_WALK_DOWN" )
	{
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_DOWN_01.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_DOWN_02.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_DOWN_03.png" ) );
	}

	return true;
}
