/**
 * @file	IResourceManager.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "ResourceId.h"
#include "IResource.h"

#include <string>

class IResourceManager
{
public:
	virtual ~IResourceManager() {};

	virtual ResourceId	CreateResource( std::string path ) = 0;
	virtual IResource *	GetResource( ResourceId id ) = 0;
};
