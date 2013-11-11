// @author	Lee JinWoo (2013.11.3)
#pragma once

#include "IResource.h"
#include "MapData.h"
#include <string>
#include <vector>

class CZoneMap;

// ----------------------------------------------------------------
//	MapHeader
// ----------------------------------------------------------------
struct MapHeader
{
	UINT	m_MapCount;
	UINT	m_TileCount;
	UINT	m_TileWidth;
	UINT	m_TileHeight;
};

// ----------------------------------------------------------------
//	TileData
// ----------------------------------------------------------------
struct TileData
{
	float	m_TileX;
	float	m_TileY;
};


// ----------------------------------------------------------------
//	CMapInfo
// ----------------------------------------------------------------
class CMapInfo : public IResource
{
public:
	CMapInfo();
	~CMapInfo(void);

	bool LoadResource( std::wstring mapType );
	CZoneMap * CreateMap();

	MapHeader GetHeader() { return m_Header; };
	std::vector< TileData > GetTiles() { return m_Tiles; };
	CMapData * GetMapData( UINT mapNo ){
		if( mapNo < m_Header.m_MapCount )
			return m_Maps[mapNo];
		else
			return nullptr;
	}

	// --------------------------------
	//	IResource interface
	// --------------------------------
	void Release();

private:
	friend class CResourceManager;
	bool LoadTileData();
	bool LoadMaps();

	MapHeader					m_Header;	//	Map Header		( 16 byte		)
	std::vector< TileData >		m_Tiles;	//	TileInfo list	(  8 byte * N	)
	std::vector< CMapData * >	m_Maps;		//	Map (Tile list)	(  4 byte * M	)
};
