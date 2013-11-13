
//@author : 이인재, 조익성 (2013. 11. 01)

#pragma once

#include "IResource.h"
#include "GameObject.h"
#include <string>
#include "ZoneMap.h"
#include "ZoneInfo.h"

class CPC;

class CZone
{
public:
	CZone(void);
	CZone( std::wstring id );
	virtual ~CZone(void);
	
	bool Update( float deltaTime, Position & PlayerPosition );
	void Render( Position & cameraPosition );

	bool LoadZone();
	void Enter( CPC * player, CZone * from );
	void SetMap( CZoneMap * map) { m_Map = map; }
	std::list< CGameObject * > GetObject() { return m_Object; }
	CZoneMap * GetMapData() { return m_Map; }

	void Release();

private:
	friend class CZoneInfo;
	int							m_Width, 
								m_Height;
	CPC *						m_Player;
	std::list< CGameObject * >	m_Object;
	std::wstring				m_ZoneId;
	CZoneMap *					m_Map;
};