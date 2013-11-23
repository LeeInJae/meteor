#pragma once

#include "IResource.h"
#include "Position.h"
#include "GameObject.h"
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

	void SetSize( UINT x, UINT y, float width, float height );
	void AddSprite( int row, CSprite * sprite );
	bool Update( Position & playerPosition );
	void Render();

	Direction FindPath( const Position & start, const Position & destination, const std::list< CGameObject * > objects ) const; // 해당 좌표의 이동 가능 여부

	// --------------------------------
	//	IResource interface
	// --------------------------------
	void Release();

private:
	UINT					m_SizeX;
	UINT					m_SizeY;
	float					m_Width;
	float					m_Height;
	Position				m_Position;
	std::vector<std::vector<CSprite *>>	m_Sprites;
};
