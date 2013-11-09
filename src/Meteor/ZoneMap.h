#pragma once

#include "Sprite.h"
#include "MapInfo.h"
#include <vector>
#include <string>

// ================================================================
//	CZoneMap
// ================================================================
class CZoneMap
{
public:
	CZoneMap( std::wstring mapType, UINT mapNo );
	~CZoneMap(void);

	bool LoadMap();
	void Update( float x, float y );
	bool Render();

private:
	int						m_X, 
							m_Y;
	std::vector<CSprite *>	m_Sprites;
	CMapInfo *				m_MapInfo;
	std::wstring			m_MapType;
	UINT					m_MapNo;
	CMapData *				m_MapData;
};
