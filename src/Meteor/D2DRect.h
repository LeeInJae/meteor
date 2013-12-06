#pragma once

#include "Position.h"
#include <d2d1.h>

class CD2DRect
{
public:
	CD2DRect();
	~CD2DRect();

	void SetRect( float left, float top, float right, float bottom );
	void SetPosition( const Position & position );
	void SetColor( float red, float green, float blue, float opacity );
	void SetFill( bool fill ) { m_Fill = fill; }
	void Render();

protected:
	float		m_ColorR;
	float		m_ColorG;
	float		m_ColorB;
	float		m_Opacity;

	Position				m_Position;
	bool					m_Fill;
	D2D1_RECT_F				m_Rect;
	ID2D1SolidColorBrush *	m_Brush;
};
