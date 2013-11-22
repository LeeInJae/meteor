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
	Vector direction = end - start;
	Vector hypotenuse = m_Center - start;
	float dirSquare		= direction * direction;
	float dotProduct	= direction * hypotenuse;
	float hypoSquare	= hypotenuse * hypotenuse;
	float radiusSquare	= m_Radius * m_Radius;

	if ( dirSquare <= 0.000001f )
		return false;

	if ( hypoSquare > radiusSquare && dotProduct < 0.0f )
		return false;

	float projectionSquare = dotProduct * dotProduct / dirSquare;
	float determinant = projectionSquare - hypoSquare + radiusSquare;

	if ( determinant < 0.0f )
		return false;

	intersect = start + ( ( end - start ) * - ( ( sqrt( projectionSquare ) + sqrt( determinant ) ) / sqrt( dirSquare ) ) );

	return true;
}
