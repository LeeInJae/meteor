//@author : Lee JinWoo (2013.11.23)
#pragma once

#include <cmath>

enum Direction
{
	NONE,
	UP,
	UP_RIGHT,
	RIGHT,
	DOWN_RIGHT,
	DOWN,
	DOWN_LEFT,
	LEFT,
	UP_LEFT,
};

const static float PI = 3.14159265359f;

template< typename Type >
Direction GetDirection( Type startX, Type startY, Type targetX, Type targetY )
{
	float diffX = static_cast<float>( targetX - startX );
	float diffY = static_cast<float>( targetY - startY );

	float slope = atan2( -diffY, diffX );
	int slopeLevel = static_cast<int>( ( slope + PI ) * 8.0f / PI );	// 0 ~ 16 level
	switch ( slopeLevel )
	{
	case 1: case 2:
		return DOWN_LEFT;
	case 3: case 4:
		return DOWN;
	case 5: case 6:
		return DOWN_RIGHT;
	case 7: case 8:
		return RIGHT;
	case 9: case 10:
		return UP_RIGHT;
	case 11: case 12:
		return UP;
	case 13: case 14:
		return UP_LEFT;
	default:	// 0, 15, 16
		return LEFT;
	}
}