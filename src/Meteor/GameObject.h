//@author : 조익성 (2013.10.23)

#pragma once

#include "Animation.h"
#include "Direction.h"
#include "Position.h"
#include "Circle.h"
#include "IEventSubject.h"
#include "IEventListener.h"
#include "ResourceManager.h"

class CZone;

// TODO: Redesign with lambda and closure to cancel event
enum EventType
{
	EVENT_CANCEL,
	EVENT_MOVE,
	EVENT_HIT,
	EVENT_DEAD,
};

// 게임상의 각 개체
class CGameObject : public IEventListener<CGameObject>
{
public:
	CGameObject(void);
	virtual ~CGameObject(void);

	void				SetPosition( float x, float y )			{ m_Position.x = x; m_Position.y = y; }
	void				SetDirection( Direction direction )		{ m_Direction = direction; }
	const Position &	GetPosition() const						{ return m_Position; }
	Direction			GetDirection() const					{ return m_Direction; }

	void	SetZone( CZone * zone )	{ m_Zone = zone; }
	CZone *	GetZone() const			{ return m_Zone; }

	void				SetSubject( IEventSubject<CGameObject> * subject ) { m_EventSubject = subject; }
	void				SetEventType( EventType type )			{ m_EventType = type; }
	IEventSubject<CGameObject> * GetSubject() const				{ return m_EventSubject; }
	EventType			GetEventType() const					{ return m_EventType; }
	CCircle				GetBoundary() const						{ return m_Boundary + m_Position; }

	virtual bool		Update( float deltaTime );
	virtual void		Render( const Position & cameraPosition );
	virtual bool		Move( float x, float y );
	virtual bool		Move( Direction direction, float distance );
	virtual CAnimation * GetAnimation() const = 0;
	
	// --------------------------------
	//	IEventListener
	// --------------------------------
	void EventHandler( CGameObject * event ) override;
	
protected:
	CZone *								m_Zone;
	Position							m_Position;
	Direction							m_Direction;
	CCircle								m_Boundary;
	EventType							m_EventType;
	std::map<ResourceId, CAnimation *>	m_Animation;
	IEventSubject<CGameObject> *		m_EventSubject;
	std::vector<CGameObject *>			m_EventBucket;
};
