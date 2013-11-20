#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject(void)
	: m_EventSubject( nullptr )
	, m_Direction( DOWN )
	, m_Boundary( 0.0f, 10.0f, 30.0f )
{
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
