#pragma once

#include "Position.h"

class CCircle
{
public:
	CCircle( Position center, float radius );
	CCircle( float centerX, float centerY, float radius );
	virtual ~CCircle(void);

	CCircle operator+( const Position & position ) const;
	bool isIntersected( const CCircle & other ) const;

private:
	Position	m_Center;
	float		m_Radius;
};
