/**
 * @file	Animation.cpp
 * @brief
 * @author	Lee InJae
 *
 */

#include "stdafx.h"
#include "Animation.h"

#include "Sprite.h"
#include <timeapi.h>

// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CAnimation::CAnimation()
	: m_ElapsedTime(0)
	, m_FrameSetNumber( 10 )
{
	m_Sprites.push_back( CSprite::Create( L"test1.png" ) );
	m_Sprites.push_back( CSprite::Create( L"test2.png" ) );
	m_Sprites.push_back( CSprite::Create( L"test3.png" ) );
}

CAnimation::CAnimation( int frameSetNumber )
{
	m_ElapsedTime = 0;
	m_FrameSetNumber = frameSetNumber;
	m_Sprites.push_back( CSprite::Create( L"test1.png" ) );
	m_Sprites.push_back( CSprite::Create( L"test2.png" ) );
	m_Sprites.push_back( CSprite::Create( L"test3.png" ) );
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

	if( m_ElapsedTime >= float( 1000 / m_FrameSetNumber ) )
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
