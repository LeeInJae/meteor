#include "stdafx.h"
#include "AnimationInfo.h"
#include "ResourceManager.h"
#include "Animation.h"
#include "SpriteInfo.h"

CAnimationInfo::CAnimationInfo(void)
	: m_Fps( 0 )
{
}


CAnimationInfo::~CAnimationInfo(void)
{
	m_SpriteId.clear();
}


bool CAnimationInfo::LoadResource( ResourceId id )
{
	if ( id == L"character_walk_left" )
	{
		m_SpriteId.push_back( L"character_walk_left_01" );
		m_SpriteId.push_back( L"character_walk_left_02" );
		m_SpriteId.push_back( L"character_walk_left_03" );
	}

	if ( id == L"character_walk_right" )
	{
		m_SpriteId.push_back( L"character_walk_right_01" );
		m_SpriteId.push_back( L"character_walk_right_02" );
		m_SpriteId.push_back( L"character_walk_right_03" );
	}

	if ( id == L"character_walk_up" )
	{
		m_SpriteId.push_back( L"character_walk_up_01" );
		m_SpriteId.push_back( L"character_walk_up_02" );
		m_SpriteId.push_back( L"character_walk_up_03" );
	}

	if ( id == L"character_walk_down" )
	{
		m_SpriteId.push_back( L"character_walk_down_01" );
		m_SpriteId.push_back( L"character_walk_down_02" );
		m_SpriteId.push_back( L"character_walk_down_03" );
	}



	if ( id == L"skeleton_mage_walk_left" )
	{
		m_SpriteId.push_back( L"skeleton_mage_walk_left_01" );
		m_SpriteId.push_back( L"skeleton_mage_walk_left_02" );
		m_SpriteId.push_back( L"skeleton_mage_walk_left_03" );
	}

	if ( id == L"skeleton_mage_walk_right" )
	{
		m_SpriteId.push_back( L"skeleton_mage_walk_right_01" );
		m_SpriteId.push_back( L"skeleton_mage_walk_right_02" );
		m_SpriteId.push_back( L"skeleton_mage_walk_right_03" );
	}

	if ( id == L"skeleton_mage_walk_up" )
	{
		m_SpriteId.push_back( L"skeleton_mage_walk_up_01" );
		m_SpriteId.push_back( L"skeleton_mage_walk_up_02" );
		m_SpriteId.push_back( L"skeleton_mage_walk_up_03" );
	}

	if ( id == L"skeleton_mage_walk_down" )
	{
		m_SpriteId.push_back( L"skeleton_mage_walk_down_01" );
		m_SpriteId.push_back( L"skeleton_mage_walk_down_02" );
		m_SpriteId.push_back( L"skeleton_mage_walk_down_03" );
	}

	return true;
}


// ----------------------------------------------------------------
//	CreateAnimation
// ----------------------------------------------------------------
CAnimation * CAnimationInfo::CreateAnimation()
{
	CAnimation * animation = new CAnimation();

	animation->SetSpeed( m_Fps );

	for ( auto spriteId : m_SpriteId )
	{
		CSpriteInfo * spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( spriteId );
		animation->AddSprite( spriteInfo->CreateSprite() );

		SafeRelease( spriteInfo );
	}

	return animation;
}


// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CAnimationInfo::Release()
{
	CResourceManager::GetInstance().ReleaseResource(this);
}
