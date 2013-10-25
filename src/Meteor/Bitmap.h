/**
 * @file	ResourceManager.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "IResource.h"
#include <string>
#include <wincodec.h>
#include <d2d1.h>


class CBitmap : public IResource
{
public:
	CBitmap(){}
	virtual ~CBitmap(){}

	static CBitmap* CreateResource( std::wstring path );
	virtual void Destroy() = 0;
	void		 Release();
};

class CD2DTexture : public CBitmap
{
public:
	CD2DTexture();
	CD2DTexture( std::wstring path );
	
	virtual ~CD2DTexture();
	void	Destroy();

	ID2D1Bitmap* GetD2DBitmap() const { return m_D2DBitmap; }

private:
	static IWICImagingFactory*	g_pWICFactory;
	ID2D1Bitmap*				m_D2DBitmap;
	IWICFormatConverter*		m_FmtConverter;
protected:
	std::wstring m_Path;
};