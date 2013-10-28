/**
 * @file	D2DBitmap.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "IResource.h"
#include <string>
#include <wincodec.h>
#include <d2d1.h>


class CD2DBitmap : public IResource
{
public:
	CD2DBitmap();
	virtual ~CD2DBitmap();

	bool			LoadResource( std::wstring path );
	void			Release();

	ID2D1Bitmap *	GetD2DBitmap() const { return m_D2DBitmap; }

private:
	static IWICImagingFactory *	g_pWICFactory;
	ID2D1Bitmap *				m_D2DBitmap;
	IWICFormatConverter *		m_FmtConverter;

protected:
	std::wstring	m_Path;
};
