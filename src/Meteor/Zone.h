
//@author : 이인재, 조익성 (2013. 11. 01)

#pragma once

#include "IResource.h"
#include "EventSubject.h"
#include "GameObject.h"
#include <string>
#include "ZoneMap.h"
#include "ZoneInfo.h"

class CPC;

class CZone : public CEventSubject<CGameObject>
{
public:
	CZone(void);
	virtual ~CZone(void);
	
	bool Update( float deltaTime, Position & PlayerPosition );
	void Render( Position & cameraPosition );

	void SetMap( CZoneMap * map );
	void AddObject( CGameObject * object );
	void SetRandomPosition( CGameObject * object );
	void Enter( CPC * player, CZone * from );
	const std::list< CGameObject * > &	GetObjects() const	{ return m_Object; }
	const CPC *							GetPlayer()	const	{ return m_Player; }
	CZoneMap *							GetMapData() const	{ return m_Map; }

	void SendEvent( CGameObject * event );

private:
	std::list< CGameObject * >	m_Object;
	CPC *						m_Player;
	ResourceId					m_ZoneId;
	CZoneMap *					m_Map;
};