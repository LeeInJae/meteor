#pragma once

#include "Position.h"

class CCircle
{
public:
	CCircle( Position center, float radius );
	CCircle( float centerX, float centerY, float radius );
	virtual ~CCircle(void);

	void	SetCenter( float centerX, float centerY )	{ m_Center.x = centerX; m_Center.y = centerY; }
	void	SetRadius( float radius )					{ m_Radius = radius; }
	float	GetRadius() const							{ return m_Radius; }
	CCircle	operator+( const Vector & position ) const;
	CCircle	operator+( const float radius ) const;
	bool	isIntersected( const CCircle & other ) const;
	bool	GetIntersect( const Position & start, const Position & end, Position & intersect ) const;

private:
	Position	m_Center;
	float		m_Radius;
};
