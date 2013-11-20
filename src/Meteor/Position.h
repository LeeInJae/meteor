// @author	Lee JinWoo (2013.10.20)
#pragma once

struct Position
{
	float		x;
	float		y;

	Position operator+( const Position & rhs ) const
	{
		Position position;
		position.x = x + rhs.x;
		position.y = y + rhs.y;
		return position;
	}

	Position operator-( const Position & rhs ) const
	{
		Position position;
		position.x = x - rhs.x;
		position.y = y - rhs.y;
		return position;
	}

	Position & operator+=( const Position & rhs )
	{
		x += rhs.x;
		y += rhs.y;
	}

	Position & operator-=( const Position & rhs )
	{
		x -= rhs.x;
		y -= rhs.y;
	}
};
