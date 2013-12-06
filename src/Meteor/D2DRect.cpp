#include "stdafx.h"
#include "D2DRect.h"
#include "D2DRenderer.h"


CD2DRect::CD2DRect()
	: m_Brush(nullptr)
	, m_Fill(false)
{
	SetColor( 0.0f, 0.0f, 0.0f, 1.0f );
	m_Rect.left		= 0;
	m_Rect.top		= 0;
	m_Rect.right	= 0;
	m_Rect.bottom	= 0;
}


CD2DRect::~CD2DRect()
{
	SafeRelease( m_Brush );
}


void CD2DRect::SetRect( float left, float top, float right, float bottom )
{
	m_Rect.left		= left;
	m_Rect.top		= top;
	m_Rect.right	= right;
	m_Rect.bottom	= bottom;
}


void CD2DRect::SetPosition( const Position & position )
{
	m_Position = position;
}


void CD2DRect::SetColor( float red, float green, float blue, float opacity )
{
	SafeRelease( m_Brush );
	CD2DRenderer::GetInstance().GetHwndRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(red, green, blue, opacity), &m_Brush);
}


void CD2DRect::Render()
{
	float left = CD2DRenderer::GetInstance().GetWidth() * 0.5f;
	float top = CD2DRenderer::GetInstance().GetHeight() * 0.5f;
	ID2D1HwndRenderTarget * renderTarget = CD2DRenderer::GetInstance().GetHwndRenderTarget();

	D2D1::Matrix3x2F matrix = D2D1::Matrix3x2F::Translation( left + m_Position.x, top + m_Position.y );

	renderTarget->SetTransform( matrix );
	if ( m_Fill )
		renderTarget->FillRectangle( m_Rect, m_Brush );
	else
		renderTarget->DrawRectangle( m_Rect, m_Brush );
}
