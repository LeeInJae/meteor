// @author	Lee JinWoo (2013.10.20)
#pragma once

enum BaseMode
{
	BASE_CENTER,
	BASE_TOPLEFT,
	BASE_TOPRIGHT,
	BASE_BOTTOMLEFT,
	BASE_BOTTOMRIGHT,
};

enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UP_LEFT,
	UP_RIGHT,
	DOWN_LEFT,
	DOWN_RIGHT
};

struct Position
{
	float		x;
	float		y;
	BaseMode	mode;
	Direction	direction;
};