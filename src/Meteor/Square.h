#pragma once

#include "Position.h"

class CSquare
{
public:
	CSquare();
	CSquare( CSquare & rhs );
	CSquare( Position & position, float width, float height );
	CSquare( float left, float top, float right, float bottom );
	virtual ~CSquare(void);

	CSquare operator+( const Position & position ) const;
	bool isIntersected( const CSquare & other ) const;

protected:
	float m_Left;
	float m_Top;
	float m_Right;
	float m_Bottom;
};
