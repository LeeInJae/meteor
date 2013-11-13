#pragma once

#include "IResource.h"
#include "Position.h"
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
	bool Update( Position & playerPosition );
	void Render();

	// --------------------------------
	//	IResource interface
	// --------------------------------
	void Release();

private:
	UINT					m_SizeX;
	UINT					m_SizeY;
	Position				m_Position;
	std::vector<std::vector<CSprite *>>	m_Sprites;
};
