/**
 * @file	ResourceManager.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "IResource.h"


class CBitmap : public IResource
{
	void Release();
};