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
CCircle CCircle::operator+( const Position & position ) const
{
	return CCircle( m_Center + position, m_Radius );
}


// ----------------------------------------------------------------
//	isIntersected
// ----------------------------------------------------------------
bool CCircle::isIntersected( const CCircle & other ) const
{
	Position diff	= m_Center - other.m_Center;
	float radius	= m_Radius + other.m_Radius;

	return ( diff.x * diff.x + diff.y * diff.y ) < ( radius * radius );
}
