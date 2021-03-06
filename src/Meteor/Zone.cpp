#include "stdafx.h"
#include "Zone.h"
#include "PC.h"


CZone::CZone(void)
	: m_Player(nullptr)
{
}

CZone::~CZone(void)
{
	SafeDelete( m_Map );
	for ( auto object : m_Object )
		SafeDelete( object );
}


bool CZone::Update( float deltaTime, Position & playerPosition )
{
	m_Map->Update( playerPosition );
	for ( auto object : m_Object )
		object->Update( deltaTime );

	return true;
}


void CZone::Render( Position & cameraPosition )
{
	// TODO: sort object and player by Y-axis
	m_Map->Render();

	for ( auto object : m_Object )
		object->Render( cameraPosition );

	m_Player->Render( cameraPosition );
}


void CZone::SetMap( CZoneMap * map )
{
	SafeDelete( m_Map );
	m_Map = map;
}


void CZone::AddObject( CGameObject * object )
{
	Register( object );
	object->SetSubject( this );
	object->SetZone( this );
	m_Object.push_back( object );
}


void CZone::SetRandomPosition( CGameObject * object )
{
	bool retry;
	do
	{
		retry = false;

		float x = static_cast<float>( rand() % ( 14 * 128 ) + 128 * 5 - 64 );
		float y = static_cast<float>( rand() % ( 8 * 128 ) + 128 * 4 - 64 );

		object->SetPosition( x, y );
		CCircle boundary = object->GetBoundary();

		for( auto other : m_Object )
		{
			if( object != other && boundary.isIntersected( other->GetBoundary() ) )
				retry = true;
		}

		if( ( GetDistance( m_Player->GetPosition(), object->GetPosition() ) > 512.0 )
			|| GetDistance( m_Player->GetPosition(), object->GetPosition() ) < 80.0 )
			retry = true;

	} while( retry );
}


void CZone::Enter( CPC * player, CZone * from )
{
	Register( player );
	player->SetSubject( this );
	player->SetPosition( 512 + 256, 384 + 256 );
	m_Player = player;
}

void CZone::SendEvent( CGameObject * event )
{
	switch ( event->GetEventType() )
	{
	case EVENT_CANCEL:
		return;
	case EVENT_MOVE:
		CEventSubject::SendEvent( event );
		if ( event->GetEventType() == EVENT_MOVE && ! m_Map->CanMove( event->GetPosition() ) )
			event->SetEventType( EVENT_CANCEL );
		return;
	default:
		CEventSubject::SendEvent( event );
	}
}
