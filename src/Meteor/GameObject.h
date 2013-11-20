//@author : 조익성 (2013.10.23)

#pragma once

#include "Animation.h"
#include "Position.h"
#include "Circle.h"
#include "IEventSubject.h"
#include "IEventListener.h"

// TODO: Redesign with lambda and closure to cancel event
enum EventType
{
	EVENT_CANCEL,
	EVENT_MOVE,
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

struct ObjectPosition : public Position
{
};

// 게임상의 각 개체
class CGameObject : public IEventListener<CGameObject>
{
public:
	CGameObject(void);
	virtual ~CGameObject(void);

	virtual bool Update( float deltaTime, Position & playerPosition );
	void Render( Position & cameraPosition );
	
	void SetPosition( float x, float y ) { m_Position.x = x; m_Position.y = y; }
	void SetDirection( Direction direction ) { m_Direction = direction; }
	Direction GetDirection() const { return m_Direction; }
	const Position & GetPosition() const { return m_Position; }
	virtual bool Move(float x, float y);
	virtual CAnimation * GetAnimation() const = 0;

	void SetSubject( IEventSubject<CGameObject> * subject );
	void SetEventType( EventType type ) { m_EventType = type; }
	EventType GetEventType() const { return m_EventType; }
	CCircle GetBoundary() const { return m_Boundary + m_Position; }

	// --------------------------------
	//	IEventListener
	// --------------------------------
	void EventHandler( CGameObject * event );
	
protected:
	Position			m_Position;
	Direction			m_Direction;
	CCircle				m_Boundary;
	EventType			m_EventType;
	std::map<std::wstring, CAnimation *> m_Animation;
	IEventSubject<CGameObject> * m_EventSubject;
};
