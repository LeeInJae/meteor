#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject(void)
	: m_EventSubject( nullptr )
{
	m_Position.mode = BASE_CENTER;
	m_Position.direction = DOWN;
	m_Collision = CSquare( -20, -40, 20, 40 );
}

CGameObject::~CGameObject(void)
{
}

bool CGameObject::Update( float deltaTime, Position & playerPosition )
{
	CAnimation * animation = GetAnimation();
	assert( animation );

	if ( animation )
		animation->Update( deltaTime );

	return true;
}

bool CGameObject::Render( Position & cameraPosition )
{
	CAnimation * animation = GetAnimation();
	assert( animation );

	if ( animation )
	{
		animation->SetPosition( m_Position, cameraPosition );
		animation->Render();
	}

	return true;
}


bool CGameObject::Move( float x, float y )
{
	m_EventType = EVENT_MOVE;

	m_Position.x += x;
	m_Position.y += y;

	if( m_EventSubject )
		m_EventSubject->SendEvent( this );

	if ( m_EventType == EVENT_CANCEL )
	{
		m_Position.x -= x;
		m_Position.y -= y;
		return false;
	}

	return true;
}


void CGameObject::SetSubject( IEventSubject<CGameObject> * subject )
{
	m_EventSubject = subject;
}


void CGameObject::EventHandler( CGameObject * event )
{
	if ( ! event ) return;
	if ( this == event ) return;

	if ( ( event->GetEventType() == EVENT_MOVE )
		&& GetCollision().isIntersected( event->GetCollision() ) )
		event->SetEventType( EVENT_CANCEL );
}
