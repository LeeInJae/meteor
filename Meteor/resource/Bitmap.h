/**
 * @file	Bitmap.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "IResource.h"

#include <string>

class CBitmap : public IResource
{
public:
	CBitmap();
	virtual ~CBitmap();

	void Load( std::string path );

private:
	// TODO:
	//ID2D1Bitmap * m_D2DBitmap;
};

