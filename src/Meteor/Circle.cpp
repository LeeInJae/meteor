#include "stdafx.h"
#include "Circle.h"


CCircle::CCircle( Position center, float radius )
	: m_Center( center )
	, m_Radius( radius )
{
}


CCircle::CCircle( float centerX, float centerY, float radius )
	: m_Radius( radius )
{
	m_Center.x = centerX;
	m_Center.y = centerY;
}


CCircle::~CCircle(void)
{
}


// ----------------------------------------------------------------
//	operator+
// ----------------------------------------------------------------
CCircle CCircle::operator+( const Vector & position ) const
{
	return CCircle( m_Center + position, m_Radius );
}


CCircle CCircle::operator+( const float radius ) const
{
	return CCircle( m_Center, m_Radius + radius );
}


// ----------------------------------------------------------------
//	isIntersected
// ----------------------------------------------------------------
bool CCircle::isIntersected( const CCircle & other ) const
{
	Vector vector	= m_Center - other.m_Center;
	float radius	= m_Radius + other.m_Radius;

	return ( vector * vector ) < ( radius * radius );
}


// ----------------------------------------------------------------
//	GetIntersect
// ----------------------------------------------------------------
bool CCircle::GetIntersect( const Position & start, const Position & end, Position & intersect ) const
{
	float x = m_Center.x;
	float y = m_Center.y;
	float r = m_Radius;

	Position point[4];

	point[0].x = x - r;
	point[0].y = y - r;
	point[1].x = x - r;
	point[1].y = y + r;
	point[2].x = x + r;
	point[2].y = y - r;
	point[3].x = x + r;
	point[3].y = y + r;

	float determinent[4];

	for ( int i = 0; i < 4; ++i )
		determinent[i] =
			start.x * end.y - end.x * start.y +
			end.x * point[i].y + point[i].x * end.y +
			point[i].x * start.x + start.x * point[i].y;

	return true;
}
