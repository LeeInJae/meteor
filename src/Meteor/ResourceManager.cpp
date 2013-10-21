/**
 * @file	ResourceManager.cpp
 * @brief
 * @author	Lee JinWoo
 *
 */

#include "stdafx.h"
#include "ResourceManager.h"

// ----------------------------------------------------------------
//	CreateResource
// ----------------------------------------------------------------
ResourceId CResourceManager::CreateResource( std::string path )
{
	int id = 0;

	return id;
}

// ----------------------------------------------------------------
//	GetResource
// ----------------------------------------------------------------
IResource * CResourceManager::GetResource( ResourceId id )
{
	IResource * resource = m_ResourceMap[id];

	return resource;
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
//	Others
// ----------------------------------------------------------------
CResourceManager::CResourceManager() {}
