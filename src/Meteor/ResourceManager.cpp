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
//	CreateResource
// ----------------------------------------------------------------
bool CResourceManager::LoadResource( ResourceId id )
{
	IResource * resource = nullptr;

	if( id == L"CHARACTOR_WALK_LEFT" )
	{
		CAnimation * animation = new CAnimation();
		animation->AddSprite( CSprite::Create( L"CHARACTOR_WALK_LEFT_01.png" ) );
		animation->AddSprite( CSprite::Create( L"CHARACTOR_WALK_LEFT_02.png" ) );
		animation->AddSprite( CSprite::Create( L"CHARACTOR_WALK_LEFT_03.png" ) );
		resource = animation;
	}

	if( id == L"CHARACTOR_WALK_RIGHT" )
	{
		CAnimation * animation = new CAnimation();
		animation->AddSprite( CSprite::Create( L"CHARACTOR_WALK_RIGHT_01.png" ) );
		animation->AddSprite( CSprite::Create( L"CHARACTOR_WALK_RIGHT_02.png" ) );
		animation->AddSprite( CSprite::Create( L"CHARACTOR_WALK_RIGHT_03.png" ) );
		resource = animation;
	}

	if( id == L"CHARACTOR_WALK_UP" )
	{
		CAnimation * animation = new CAnimation();
		animation->AddSprite( CSprite::Create( L"CHARACTOR_WALK_UP_01.png" ) );
		animation->AddSprite( CSprite::Create( L"CHARACTOR_WALK_UP_02.png" ) );
		animation->AddSprite( CSprite::Create( L"CHARACTOR_WALK_UP_03.png" ) );
		resource = animation;
	}

	if( id == L"CHARACTOR_WALK_DOWN" )
	{
		CAnimation * animation = new CAnimation();
		animation->AddSprite( CSprite::Create( L"CHARACTOR_WALK_DOWN_01.png" ) );
		animation->AddSprite( CSprite::Create( L"CHARACTOR_WALK_DOWN_02.png" ) );
		animation->AddSprite( CSprite::Create( L"CHARACTOR_WALK_DOWN_03.png" ) );
		resource = animation;
	}

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
