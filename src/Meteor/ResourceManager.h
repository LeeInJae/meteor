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
	// --------------------------------
	//	IResourceManager interface
	// --------------------------------
	IResource *	GetResource( ResourceId id );
	void ReleaseResource( IResource * resource );

	// --------------------------------
	//	IResourceManager interface
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
	friend class CGameManager;
	CResourceManager() {};
	CResourceManager( const CResourceManager & );
	CResourceManager & operator=( const CResourceManager & );
	~CResourceManager();

	bool LoadResource( ResourceId id );
	void Clear();

	std::map<ResourceId, IResource *> m_ResourceMap;
	std::map<InstanceId, IResource *> m_InstanceMap;
};
