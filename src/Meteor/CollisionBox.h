//@author : ���ͼ� (2013.10.30)

#pragma once

#include "GameObject.h"

enum Shape{
	CIRCLE,
	SQUARE
};

// �浹 ����
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

