/**
 * @file	ResourceManager.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "IResource.h"
#include "IResourceManager.h"

#include <vector>
#include <map>

class CSpriteInfo;
class CAnimationInfo;
class CMapInfo;
class CZoneInfo;

class CResourceManager : public IResourceManager
{
public:
	void Clear();

	// --------------------------------
	//	IResourceManager interface
	// --------------------------------
	bool LoadResource( ResourceId id );
	IResource *	GetResource( ResourceId id );
	void ReleaseResource( IResource * resource );

	// --------------------------------
	//	Additional methods
	// --------------------------------
	CSpriteInfo *		GetSpriteInfo( ResourceId spriteId );
	CAnimationInfo *	GetAnimationInfo( ResourceId animationId );
	CZoneInfo *			GetZoneInfo( ResourceId zoneId );
	CMapInfo *			GetMapInfo( ResourceId mapId );

	// --------------------------------
	//	GetInstance
	// --------------------------------
	static CResourceManager & GetInstance();

private:
	CResourceManager() {};
	CResourceManager( const CResourceManager & );
	CResourceManager & operator=( const CResourceManager & );
	~CResourceManager();

	std::map<ResourceId, IResource *> m_ResourceMap;
};
