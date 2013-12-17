// @author	Lee JinWoo (2013.10.20)
#pragma once

struct Vector
{
	float		x;
	float		y;

	Vector operator+( const Vector & rhs ) const
	{
		Vector vector;
		vector.x = x + rhs.x;
		vector.y = y + rhs.y;
		return vector;
	}

	Vector operator-( const Vector & rhs ) const
	{
		Vector vector;
		vector.x = x - rhs.x;
		vector.y = y - rhs.y;
		return vector;
	}

	float operator*( const Vector & position ) const
	{
		return ( x * position.x + y * position.y );
	}

	Vector operator*( const float ratio ) const
	{
		Vector vector;
		vector.x = x * ratio;
		vector.y = y * ratio;
		return vector;
	}

	Vector & operator+=( const Vector & rhs )
	{
		x += rhs.x;
		y += rhs.y;
	}

	Vector & operator-=( const Vector & rhs )
	{
		x -= rhs.x;
		y -= rhs.y;
	}
};

struct Position : public Vector
{
	Position operator+( const Vector & rhs ) const
	{
		Position position;
		position.x = x + rhs.x;
		position.y = y + rhs.y;
		return position;
	}
};

template< typename Type >
float GetDistance( Type startX, Type startY, Type targetX, Type targetY )
{
	float diffX = static_cast<float>( targetX - startX );
	float diffY = static_cast<float>( targetY - startY );

	return sqrt( pow( diffX, 2 ) + pow( diffY, 2 ) );
}

static inline float GetDistance( Position start, Position end )
{
	return GetDistance( start.x, start.y, end.x, end.y );
}
