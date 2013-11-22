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