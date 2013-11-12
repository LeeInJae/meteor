/**
 * @file	ResourceManager.cpp
 * @brief
 * @author	Lee JinWoo
 *
 */

#include "stdafx.h"
#include "ResourceManager.h"
#include "D2DBitmap.h"
#include "SpriteInfo.h"
#include "AnimationInfo.h"
#include "ZoneInfo.h"
#include "MapInfo.h"

// ----------------------------------------------------------------
//	Desrtuctor
// ----------------------------------------------------------------
CResourceManager::~CResourceManager()
{
	Clear();
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
CSpriteInfo * CResourceManager::GetSpriteInfo( ResourceId spriteId )
{
	IResource * resource = GetResource( spriteId );

	return static_cast<CSpriteInfo *>( resource );
}


// ----------------------------------------------------------------
//	GetAnimation
// ----------------------------------------------------------------
CAnimationInfo * CResourceManager::GetAnimationInfo( ResourceId animationId )
{
	IResource * resource = GetResource( animationId );

	return static_cast<CAnimationInfo *>( resource );
}


// ----------------------------------------------------------------
//	GetMapInfo
// ----------------------------------------------------------------
CMapInfo * CResourceManager::GetMapInfo( ResourceId mapId )
{
	IResource * resource = GetResource( mapId );

	return static_cast<CMapInfo *>( resource );
}


// ----------------------------------------------------------------
//	GetZoneInfo
// ----------------------------------------------------------------
CZoneInfo * CResourceManager::GetZoneInfo( ResourceId zoneId )
{
	IResource * resource = GetResource( zoneId );

	return static_cast<CZoneInfo *>( resource );
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

	if ( m_ResourceMap.erase( resource->m_Key ) > 0 )
		delete resource;
}


// ----------------------------------------------------------------
//	LoadResource
// ----------------------------------------------------------------
bool CResourceManager::LoadResource( ResourceId id )
{
	IResource * resource = nullptr;

	if ( m_ResourceMap[id] )
		return true;

	if ( id.find( L".png" ) != std::wstring::npos )
	{
		CD2DBitmap * bitmap = new CD2DBitmap();
		bitmap->LoadResource( id );
		resource = bitmap;
	}

	if ( ( id == L"character_walk_left_01" )
		|| ( id == L"character_walk_left_02" )
		|| ( id == L"character_walk_left_03" )
		|| ( id == L"character_walk_right_01" )
		|| ( id == L"character_walk_right_02" )
		|| ( id == L"character_walk_right_03" )
		|| ( id == L"character_walk_up_01" )
		|| ( id == L"character_walk_up_02" )
		|| ( id == L"character_walk_up_03" )
		|| ( id == L"character_walk_down_01" )
		|| ( id == L"character_walk_down_02" )
		|| ( id == L"character_walk_down_03" ) )
	{
		CSpriteInfo * spriteInfo = new CSpriteInfo();
		spriteInfo->LoadResource( id );
		resource = spriteInfo;
	}

	if ( ( id == L"character_walk_left" )
		|| ( id == L"character_walk_right" )
		|| ( id == L"character_walk_up" )
		|| ( id == L"character_walk_down" ) )
	{
		CAnimationInfo * animationInfo = new CAnimationInfo();
		animationInfo->LoadResource( id );
		resource = animationInfo;
	}

	if ( id == L"zone_village" )
	{
		CZoneInfo * zoneInfo = new CZoneInfo();
		zoneInfo->LoadResource( L"zone_village" );
		resource = zoneInfo;
	}

	if( id == L"map_village" )
	{
		CMapInfo * mapInfo = new CMapInfo();
		mapInfo->LoadResource( L"map_village" );
		resource = mapInfo;
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
//	Clear
// ----------------------------------------------------------------
void CResourceManager::Clear()
{
	for ( auto resource : m_ResourceMap )
		delete resource.second;
	m_ResourceMap.clear();
}
