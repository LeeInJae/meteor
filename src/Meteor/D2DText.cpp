/**
 * @file	D2DText.cpp
 * @brief
 * @author	Lee JinWoo
 *
 */

#include "stdafx.h"
#include "D2DText.h"

// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CD2DText::CD2DText(void)
	: m_pD2DRenderer( & CD2DRenderer::GetInstance() )
	, m_Text( L"" )
	, m_FontFace( L"" )
	, m_FontSize(0)
	, m_ColorR(0)
	, m_ColorG(0)
	, m_ColorB(0)
	, m_Opacity(1.f)
	, m_Bold(false)
	, m_Italic(false)
	, m_DWriteFactory(nullptr)
	, m_TextFormat(nullptr)
	, m_Brush(nullptr)
	, m_PosX(0)
	, m_PosY(0)
{
}

// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
CD2DText::~CD2DText(void)
{
	SafeRelease( m_DWriteFactory );
	SafeRelease( m_TextFormat );
	SafeRelease( m_Brush );
}

// ----------------------------------------------------------------
//	SetPosition
// ----------------------------------------------------------------
void CD2DText::SetPosition( float x, float y )
{
	m_PosX = x;
	m_PosY = y;
}

// ----------------------------------------------------------------
//	SetText
// ----------------------------------------------------------------
void CD2DText::SetText( std::wstring text )
{
	m_Text = text;
}

// ----------------------------------------------------------------
//	SetText
// ----------------------------------------------------------------
void CD2DText::SetFont( std::wstring fontFace, float fontSize )
{
	m_FontFace = fontFace;
	m_FontSize = fontSize;
}

// ----------------------------------------------------------------
//	SetTextFormat
// ----------------------------------------------------------------
void CD2DText::SetTextFormat()
{
	SafeRelease( m_TextFormat );
	m_DWriteFactory->CreateTextFormat( m_FontFace.c_str(), NULL,
		m_Bold ? DWRITE_FONT_WEIGHT_BOLD : DWRITE_FONT_WEIGHT_NORMAL,
		m_Italic ? DWRITE_FONT_STYLE_ITALIC : DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL, m_FontSize, L"ko", &m_TextFormat );
}

// ----------------------------------------------------------------
//	Render
// ----------------------------------------------------------------
void CD2DText::Render()
{
	m_Matrix = D2D1::Matrix3x2F::Translation( m_PosX, m_PosY );
	m_pD2DRenderer->GetHwndRenderTarget()->SetTransform( m_Matrix );

	SetTextFormat();

	m_pD2DRenderer->GetHwndRenderTarget()->DrawTextW(
		m_Text.c_str(),
		wcslen(m_Text.c_str()), m_TextFormat, 
		D2D1::RectF( 0, 0,
			m_pD2DRenderer->GetHwndRenderTarget()->GetSize().width,
			m_pD2DRenderer->GetHwndRenderTarget()->GetSize().height),
		m_Brush );
}


// ----------------------------------------------------------------
//	LoadResource
// ----------------------------------------------------------------
bool CD2DText::LoadResource( ResourceId id )
{
	DWriteCreateFactory( DWRITE_FACTORY_TYPE_SHARED, __uuidof(m_DWriteFactory), reinterpret_cast<IUnknown**>(&m_DWriteFactory) );
	m_pD2DRenderer->GetHwndRenderTarget()->CreateSolidColorBrush( D2D1::ColorF(m_ColorR,m_ColorG,m_ColorB), &m_Brush );

	return true;
}


// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CD2DText::Release()
{
}
