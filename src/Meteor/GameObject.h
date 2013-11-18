//@author : 조익성 (2013.10.23)

#pragma once

#include "Animation.h"
#include "Position.h"

// 게임상의 각 개체
class CGameObject
{
public:
	CGameObject(void);
	virtual ~CGameObject(void);
	
	virtual bool Update( float deltaTime, Position & playerPosition );
	bool Render( Position & cameraPosition );
	
	void SetPosition( float x, float y ) { m_Position.x = x; m_Position.y = y; }
	void SetDirection( Direction direction ) { m_Position.direction = direction; }
	void SetPosition( float x, float y, Direction direction ) { SetPosition( x, y ); SetDirection( direction ); }

	Direction GetDirection() const { return m_Position.direction; }
	const Position & GetPosition() const { return m_Position; }
	virtual bool Move(float x, float y);
	virtual CAnimation * GetAnimation() const = 0;

protected:
	Position m_Position;
	std::map<std::wstring, CAnimation *> m_Animation;

	bool IsCanMove(int x, int y); // 해당 좌표의 이동 가능 여부
};
