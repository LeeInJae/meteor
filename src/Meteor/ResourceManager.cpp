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
	assert( resource );
	if ( resource == nullptr )
		return;

	resource->m_ReferenceCount--;
	if ( resource->m_ReferenceCount > 0 )
		return;

	if ( m_ResourceMap.erase( resource->m_Id ) > 0 )
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
	else if ( id.find( L"zone_" ) != std::wstring::npos )
	{
		CZoneInfo * zoneInfo = new CZoneInfo();
		zoneInfo->LoadResource( id );
		resource = zoneInfo;
	}
	else if( id.find( L"map_" ) != std::wstring::npos )
	{
		CMapInfo * mapInfo = new CMapInfo();
		mapInfo->LoadResource( id );
		resource = mapInfo;
	}
	else if ( id.find( L"_0" ) != std::wstring::npos )
	{
		CSpriteInfo * spriteInfo = new CSpriteInfo();
		spriteInfo->LoadResource( id );
		resource = spriteInfo;
	}
	else if ( id.find( L"skill_" ) != std::wstring::npos
		|| id.find( L"character_" ) != std::wstring::npos
		|| id.find( L"skeleton_" ) != std::wstring::npos )
	{
		CAnimationInfo * animationInfo = new CAnimationInfo();
		animationInfo->LoadResource( id );
		resource = animationInfo;
	}

	if ( resource )
	{
		resource->m_Id= id;
		m_ResourceMap[id] = resource;
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
