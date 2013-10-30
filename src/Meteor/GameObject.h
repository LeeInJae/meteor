//@author : 조익성 (2013.10.23)

#pragma once

#include "Animation.h"

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UP_LEFT,
	UP_RIGHT,
	DOWN_LEFT,
	DOWN_RIGHT
};

// 게임상의 각 개체
class CGameObject
{
public:
	CGameObject(void);
	virtual ~CGameObject(void);
	
	virtual bool Update( float deltaTime );
	bool Render();
	
	bool SetPosition(int x, int y) {
		m_X = x;
		m_Y = y;
	}

	bool Move(int x, int y) { return false; }
	int GetX() const { return m_X; }
	int GetY() const { return m_Y; }
	Direction GetDirection() { return m_Direction; }
	void SetDirection( Direction direction ) { m_Direction = direction; }
	virtual CAnimation * GetAnimation() const = 0;

protected:
	int m_X;
	int m_Y;
	Direction m_Direction;
	std::vector<CAnimation *> m_Animation;

	bool IsCanMove(int x, int y); // 해당 좌표의 이동 가능 여부
};
