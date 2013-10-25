/**
 * @file	Animation.cpp
 * @brief
 * @author	Lee InJae
 *
 */

#include "stdafx.h"
#include "Animation.h"

#include "Sprite.h"

// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CAnimation::CAnimation()
	: m_ElapsedTime(0)
{
	m_Sprites.push_back( CSprite::Create( L"aaa.png" ) );
	m_Sprites.push_back( CSprite::Create( L"aaa.png" ) );
	m_Sprites.push_back( CSprite::Create( L"aaa.png" ) );
}

// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
CAnimation::~CAnimation()
{
}

// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
bool CAnimation::Update( float deltaTime )
{
}

// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
bool CAnimation::Render()
{
}
