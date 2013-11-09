
//@author : 이인재, 조익성 (2013. 11. 01)

#pragma once

#include "GameObject.h"
#include <string>
#include "ZoneMap.h"
#include "ZoneInfo.h"

class CZone
{
public:
	CZone(void);
	CZone( std::wstring id );
	virtual ~CZone(void);
	
	bool LoadZone();
	std::list< CGameObject * > GetObject() { return m_Object; }
	CZoneMap * GetMapData() { return m_Map; }

private:
	int							m_Width, 
								m_Height;
	std::list< CGameObject * >	m_Object;
	std::wstring				m_ZoneId;
	CZoneMap *					m_Map;
};