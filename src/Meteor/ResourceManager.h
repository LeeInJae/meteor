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
	bool LoadResource( ResourceId id );
	IResource *	GetResource( ResourceId id );
	void ReleaseResource( IResource * resource );

	// --------------------------------
	//	IResourceManager interface
	// --------------------------------
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

	std::map<ResourceId, IResource *> m_ResourceMap;
};
