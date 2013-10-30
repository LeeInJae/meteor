//@author : 조익성 (2013.10.23)

#pragma once

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

	bool Render();
	bool Update();

	bool SetPosition(int x, int y){
		m_X = x;
		m_Y = y;
	};
	bool Move(int x, int y);
	int GetX(){ return m_X;};
	int GetY(){ return m_Y;};
	Direction GetDirection(){ return m_Direction;};

protected:
	int m_X;
	int m_Y;
	Direction m_Direction;

	void SetDirection(Direction direction){ m_Direction = direction;};
	bool IsCanMove(int x, int y); // 해당 좌표의 이동 가능 여부
};

