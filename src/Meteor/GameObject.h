//@author : 조익성 (2013.10.23)

#pragma once

#include "Animation.h"
#include "Position.h"
#include "Square.h"
#include "IEventSubject.h"
#include "IEventListener.h"

// TODO: Redesign with lambda and closure to cancel event
enum EventType
{
	EVENT_CANCEL,
	EVENT_MOVE,
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
	void SetDirection( Direction direction ) { m_Position.direction = direction; }
	void SetPosition( float x, float y, Direction direction ) { SetPosition( x, y ); SetDirection( direction ); }

	Direction GetDirection() const { return m_Position.direction; }
	const Position & GetPosition() const { return m_Position; }
	virtual bool Move(float x, float y);
	virtual CAnimation * GetAnimation() const = 0;

	void SetSubject( IEventSubject<CGameObject> * subject );
	void SetEventType( EventType type ) { m_EventType = type; }
	EventType GetEventType() const { return m_EventType; }
	CSquare GetCollision() const { return m_Collision + m_Position; }

	// --------------------------------
	//	IEventListener
	// --------------------------------
	void EventHandler( CGameObject * event );
	
protected:
	Position		m_Position;
	CSquare			m_Collision;
	EventType		m_EventType;
	std::map<std::wstring, CAnimation *> m_Animation;
	IEventSubject<CGameObject> * m_EventSubject;
};
