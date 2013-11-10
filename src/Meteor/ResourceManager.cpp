/**
 * @file	ResourceManager.cpp
 * @brief
 * @author	Lee JinWoo
 *
 */

#include "stdafx.h"
#include "ResourceManager.h"

// ----------------------------------------------------------------
//	Desrtuctor
// ----------------------------------------------------------------
CResourceManager::~CResourceManager()
{
	for ( auto resource : m_ResourceMap )
		delete resource.second;
}


// ----------------------------------------------------------------
//	LoadResource
// ----------------------------------------------------------------
bool CResourceManager::LoadResource( ResourceId id )
{
	IResource * resource = nullptr;

	if ( m_ResourceMap[id] )
		return true;

	if( id == L"CHARACTOR_WALK_LEFT" )
	{
		CAnimation * animation = new CAnimation();
		animation->AddSprite( GetSprite( L"CHARACTOR_WALK_LEFT_01" ) );
		animation->AddSprite( GetSprite( L"CHARACTOR_WALK_LEFT_02" ) );
		animation->AddSprite( GetSprite( L"CHARACTOR_WALK_LEFT_03" ) );
		resource = animation;
	}

	if( id == L"CHARACTOR_WALK_LEFT_01" )
		resource = CSprite::Create( L"CHARACTOR_WALK_LEFT_01.png" );
	if( id == L"CHARACTOR_WALK_LEFT_02" )
		resource = CSprite::Create( L"CHARACTOR_WALK_LEFT_02.png" );
	if( id == L"CHARACTOR_WALK_LEFT_03" )
		resource = CSprite::Create( L"CHARACTOR_WALK_LEFT_03.png" );

	if( id == L"CHARACTOR_WALK_RIGHT" )
	{
		CAnimation * animation = new CAnimation();
		animation->AddSprite( GetSprite( L"CHARACTOR_WALK_RIGHT_01" ) );
		animation->AddSprite( GetSprite( L"CHARACTOR_WALK_RIGHT_02" ) );
		animation->AddSprite( GetSprite( L"CHARACTOR_WALK_RIGHT_03" ) );
		resource = animation;
	}

	if( id == L"CHARACTOR_WALK_RIGHT_01" )
		resource = CSprite::Create( L"CHARACTOR_WALK_RIGHT_01.png" );
	if( id == L"CHARACTOR_WALK_RIGHT_02" )
		resource = CSprite::Create( L"CHARACTOR_WALK_RIGHT_02.png" );
	if( id == L"CHARACTOR_WALK_RIGHT_03" )
		resource = CSprite::Create( L"CHARACTOR_WALK_RIGHT_03.png" );

	if( id == L"CHARACTOR_WALK_UP" )
	{
		CAnimation * animation = new CAnimation();
		animation->AddSprite( GetSprite( L"CHARACTOR_WALK_UP_01" ) );
		animation->AddSprite( GetSprite( L"CHARACTOR_WALK_UP_02" ) );
		animation->AddSprite( GetSprite( L"CHARACTOR_WALK_UP_03" ) );
		resource = animation;
	}

	if( id == L"CHARACTOR_WALK_UP_01" )
		resource = CSprite::Create( L"CHARACTOR_WALK_UP_01.png" );
	if( id == L"CHARACTOR_WALK_UP_02" )
		resource = CSprite::Create( L"CHARACTOR_WALK_UP_02.png" );
	if( id == L"CHARACTOR_WALK_UP_03" )
		resource = CSprite::Create( L"CHARACTOR_WALK_UP_03.png" );

	if( id == L"CHARACTOR_WALK_DOWN" )
	{
		CAnimation * animation = new CAnimation();
		animation->AddSprite( GetSprite( L"CHARACTOR_WALK_DOWN_01" ) );
		animation->AddSprite( GetSprite( L"CHARACTOR_WALK_DOWN_02" ) );
		animation->AddSprite( GetSprite( L"CHARACTOR_WALK_DOWN_03" ) );
		resource = animation;
	}

	if( id == L"CHARACTOR_WALK_DOWN_01" )
		resource = CSprite::Create( L"CHARACTOR_WALK_DOWN_01.png" );
	if( id == L"CHARACTOR_WALK_DOWN_02" )
		resource = CSprite::Create( L"CHARACTOR_WALK_DOWN_02.png" );
	if( id == L"CHARACTOR_WALK_DOWN_03" )
		resource = CSprite::Create( L"CHARACTOR_WALK_DOWN_03.png" );


	if ( resource )
	{
		m_ResourceMap[id] = resource;
		resource->m_Key = id;
		return true;
	}

	return false;
}

// ----------------------------------------------------------------
//	GetResource
// ----------------------------------------------------------------
IResource * CResourceManager::GetResource( ResourceId id )
{
	if ( ! LoadResource ( id ) )
		return nullptr;

	IResource * resource = m_ResourceMap[id];
	resource->m_ReferenceCount++;

	return resource;
}

// ----------------------------------------------------------------
//	GetSprite
// ----------------------------------------------------------------
CSprite * CResourceManager::GetSprite( ResourceId spriteId )
{
	IResource * resource = GetResource( spriteId );

	return static_cast<CSprite *>( resource );
}


// ----------------------------------------------------------------
//	GetAnimation
// ----------------------------------------------------------------
CAnimation * CResourceManager::GetAnimation( ResourceId animationId )
{
	IResource * resource = GetResource( animationId );

	return static_cast<CAnimation *>( resource );
}


// ----------------------------------------------------------------
//	GetMap
// ----------------------------------------------------------------
CZoneMap * CResourceManager::GetMap( ResourceId mapId )
{
	return nullptr;
}


// ----------------------------------------------------------------
//	GetInstance
// ----------------------------------------------------------------
CResourceManager & CResourceManager::GetInstance()
{
	static CResourceManager instance;

	return instance;
}


// ----------------------------------------------------------------
//	ReleaseResource
// ----------------------------------------------------------------
void CResourceManager::ReleaseResource( IResource * resource )
{
	resource->m_ReferenceCount--;
	if ( resource->m_ReferenceCount > 0 )
		return;

	m_ResourceMap.erase( resource->m_Key );
	delete resource;
}
