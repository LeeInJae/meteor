/**
 * @file	ResourceManager.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "IResource.h"
#include "IResourceManager.h"

#include <map>

class CResourceManager : public IResourceManager
{
public:
	ResourceId	CreateResource( std::string path );
	IResource *	GetResource( ResourceId id );

	static CResourceManager & GetInstance();

private:
	CResourceManager();
	CResourceManager( const CResourceManager & );
	CResourceManager & operator=( const CResourceManager & );

	std::map<ResourceId, IResource *> m_ResourceMap;
};

