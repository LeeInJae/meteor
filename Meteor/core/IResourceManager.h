/**
 * @file	IResourceManager.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include <string>

class IResourceManager
{
public:
	virtual ResourceId	CreateResource( std::string path ) = 0;
	virtual IResource *	GetResource( ResourceId id ) = 0;
};

