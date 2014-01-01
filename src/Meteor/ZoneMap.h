#pragma once

#include "IResource.h"
#include "Position.h"
#include "GameObject.h"
#include "PathFinder.h"
#include <vector>

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
	bool Update( const Position & playerPosition );
	void Render();

	Direction FindPath( const CGameObject * monster, const CGameObject * target, const std::list< CGameObject * > objects );
	bool	CanMove( const Position & position );

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
	//CPathFinder				m_PathFinder;
	std::vector<std::vector<CSprite *>>	m_Sprites;
};
