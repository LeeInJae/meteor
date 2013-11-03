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
	CZoneMap( std::string key );
	~CZoneMap(void);

	bool LoadSprite();
	void Update( float x, float y );
	bool Render();

private:
	std::vector<CSprite *>	m_Sprites;
};
