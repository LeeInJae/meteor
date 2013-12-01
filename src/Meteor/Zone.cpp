#include "stdafx.h"
#include "Zone.h"
#include "PC.h"


CZone::CZone(void)
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
	m_Object.push_back( object );
}


void CZone::Enter( CPC * player, CZone * from )
{
	Register( player );
	player->SetSubject( this );
	player->SetPosition( 512.0f, 384.0f );
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
		//if ( event->GetEventType() == EVENT_MOVE && ! m_Map->CanMove( event->GetPosition() ) )
		//	event->SetEventType( EVENT_CANCEL );
		return;
	}
}
