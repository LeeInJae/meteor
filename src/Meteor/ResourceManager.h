/**
 * @file	ResourceManager.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "IResource.h"
#include "IResourceManager.h"

#include "Animation.h"
#include "ZoneMap.h"
#include <vector>
#include <map>

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
	CSprite *		GetSprite( ResourceId spriteId );
	CAnimation *	GetAnimation( ResourceId animationId );
	CZoneMap *		GetMap( ResourceId mapId );

	// --------------------------------
	//	GetInstance
	// --------------------------------
	static CResourceManager & GetInstance();

private:
	CResourceManager() {};
	CResourceManager( const CResourceManager & );
	CResourceManager & operator=( const CResourceManager & );
	~CResourceManager();

	bool LoadResource( ResourceId id );

	std::map<ResourceId, IResource *> m_ResourceMap;
};
