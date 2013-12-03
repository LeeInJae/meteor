#include "stdafx.h"
#include "GameObject.h"

const static float SQRT2_2 = 0.70710678118f;

CGameObject::CGameObject(void)
	: m_EventSubject( nullptr )
	, m_Direction( DOWN )
	, m_Boundary( 0.0f, 10.0f, 30.0f )
{
}

CGameObject::~CGameObject(void)
{
}

bool CGameObject::Update( float deltaTime )
{
	CAnimation * animation = GetAnimation();
	assert( animation );

	if ( animation )
		animation->Update( deltaTime );

	return true;
}

void CGameObject::Render( Position & cameraPosition )
{
	CAnimation * animation = GetAnimation();
	assert( animation );

	if ( animation )
	{
		animation->SetPosition( m_Position, cameraPosition );
		animation->Render();
	}
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

bool CGameObject::Move( Direction direction, float distance )
{
	float diagonal = distance * SQRT2_2;

	switch( m_Direction )
	{
	case LEFT:
		return Move( -distance, 0 );

	case RIGHT:
		return Move( distance, 0 );

	case UP:
		return Move( 0, -distance );

	case DOWN:
		return Move( 0, distance );

	case UP_LEFT:
		return Move( -diagonal, -diagonal );

	case UP_RIGHT:
		return Move( diagonal, -diagonal );

	case DOWN_LEFT:
		return Move( -diagonal, diagonal );

	case DOWN_RIGHT:
		return Move( diagonal, diagonal );
	}

	return false;
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
		&& GetBoundary().isIntersected( event->GetBoundary() ) )
		event->SetEventType( EVENT_CANCEL );
}
