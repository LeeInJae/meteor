/**
 * @file	IResource.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

class IResource
{
public:
	virtual ~IResource() {};

	virtual void Release() = 0;
};
