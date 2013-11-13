/**
 * @file	D2DBitmap.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "IResource.h"

// agebreak : ������ �⺻ ������� stdafx.h�� ������, ������������ �Ǳ� ������ ������ �ӵ��� ����
#include <string>
#include <wincodec.h>
#include <d2d1.h>


class CD2DBitmap : public IResource
{
public:
	CD2DBitmap();
	virtual ~CD2DBitmap();

	ID2D1Bitmap *	GetD2DBitmap() const { return m_D2DBitmap; }

	// --------------------------------
	//	IResource interface
	// --------------------------------
	bool LoadResource( ResourceId id );
	void Release();

private:
	ID2D1Bitmap *				m_D2DBitmap;
	IWICFormatConverter *		m_FmtConverter;
};
