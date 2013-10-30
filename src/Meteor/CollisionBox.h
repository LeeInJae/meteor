#pragma once
#include "gameobject.h"

enum Shape{
	CIRCLE,
	SQUARE
};

class CCollisionBox :
	public CGameObject
{
public:
	CCollisionBox(Shape shapeSetting);
	~CCollisionBox(void);

protected:
	Shape m_Shape;
	int m_X;
	int m_Y;
	int m_Radius;
	int m_Width;
	int m_Height;
};

