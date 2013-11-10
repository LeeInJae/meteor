// @author	Lee JinWoo (2013.10.20)
#pragma once

#include "ResourceId.h"
#include "IResource.h"

#include <string>

class IResourceManager
{
public:
	virtual ~IResourceManager() {};

	virtual bool LoadResource( ResourceId id ) = 0;
	virtual IResource *	GetResource( ResourceId id ) = 0;
	virtual void ReleaseResource( IResource * resource ) = 0;
};
