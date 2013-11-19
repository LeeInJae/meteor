
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
	CZone( std::wstring id );
	virtual ~CZone(void);
	
	bool Update( float deltaTime, Position & PlayerPosition );
	void Render( Position & cameraPosition );

	void SetMap( CZoneMap * map );
	void AddObject( CGameObject * object );
	void Enter( CPC * player, CZone * from );
	std::list< CGameObject * > GetObject() { return m_Object; }
	CZoneMap * GetMapData() { return m_Map; }

	void SendEvent( CGameObject * event );

private:
	int							m_Width, 
								m_Height;
	CPC *						m_Player;
	std::list< CGameObject * >	m_Object;
	std::wstring				m_ZoneId;
	CZoneMap *					m_Map;
};