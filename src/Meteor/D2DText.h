/**
 * @file	D2DText.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "IResource.h"
#include "D2DRenderer.h"
#include <string>
#include <d2d1.h>
#include <dwrite.h>

class CD2DText : public IResource
{
public:
	CD2DText(void);
	virtual ~CD2DText(void);

	void				SetPosition( float x, float y );
	void				SetText( std::wstring text );
	void				SetFont( std::wstring fontFace, float fontSize );
	void				SetTextFormat();
	void				Render();
	void				Release();

private:
	CD2DRenderer *		m_pD2DRenderer;
	std::wstring		m_Text;

	// TextFormat
	std::wstring	m_FontFace;
	float		m_FontSize;
	float		m_ColorR;
	float		m_ColorG;
	float		m_ColorB;
	float		m_Opacity;
	bool		m_Bold;
	bool		m_Italic;
	IDWriteFactory *		m_DWriteFactory;
	ID2D1SolidColorBrush *	m_Brush;
	IDWriteTextFormat *		m_TextFormat;

	// Position
	float				m_PosX;
	float				m_PosY;
	D2D1::Matrix3x2F	m_Matrix;
};
