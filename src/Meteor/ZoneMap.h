#pragma once

#include "IResource.h"
#include <vector>
#include <string>

class CSprite;
class CMapInfo;
class CMapData;

// ================================================================
//	CZoneMap
// ================================================================
class CZoneMap
{
public:
	CZoneMap();
	~CZoneMap(void);

	void SetSize( UINT x, UINT y );
	void AddSprite( int row, CSprite * sprite );
	bool Update( float x, float y );
	void Render();

	// --------------------------------
	//	IResource interface
	// --------------------------------
	void Release();

private:
	UINT					m_SizeX;
	UINT					m_SizeY;
	float					m_PositionX;
	float					m_PositionY;
	std::vector<std::vector<CSprite *>>	m_Sprites;
};
