#include "stdafx.h"
#include "Square.h"


// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CSquare::CSquare(void)
	: m_Left(0), m_Top(0), m_Right(0), m_Bottom(0)
{
}

CSquare::CSquare( CSquare & rhs )
	: m_Left(rhs.m_Left), m_Top(rhs.m_Top), m_Right(rhs.m_Right), m_Bottom(rhs.m_Bottom)
{
}

CSquare::CSquare( Position & position, float width, float height )
	: m_Left( position.x - width / 2 )
	, m_Top( position.y - height / 2 )
	, m_Right( position.x + width / 2 )
	, m_Bottom( position.y + height / 2 )
{
}

CSquare::CSquare( float left, float top, float right, float bottom )
	: m_Left(left), m_Top(top), m_Right(right), m_Bottom(bottom)
{
}

CSquare::~CSquare(void)
{
}


// ----------------------------------------------------------------
//	operator+
// ----------------------------------------------------------------
CSquare CSquare::operator+( const Position & position ) const
{
	return CSquare( ( position.x + m_Left ), ( position.y + m_Top ), ( position.x + m_Right ), ( position.y + m_Bottom ) );
}


// ----------------------------------------------------------------
//	isIntersected
// ----------------------------------------------------------------
bool CSquare::isIntersected( const CSquare & other ) const
{
	return ( m_Left < other.m_Right ) && ( m_Right > other.m_Left ) && ( m_Top < other.m_Bottom ) && ( m_Bottom > other.m_Top );
}
