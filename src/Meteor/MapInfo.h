// @author	Lee JinWoo (2013.11.3)
#pragma once

#include "IResource.h"
#include "MapData.h"
#include "Sprite.h"

#include <string>
#include <vector>

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
	CMapInfo( std::wstring mapType );
	~CMapInfo(void);

	bool LoadResource();
	void Release();

private:
	bool LoadTileData();
	bool LoadMaps();

	std::wstring m_MapType;

	//	Map Header ( 16 byte )
	MapHeader m_Header;

	//	TileInfo list ( 16 byte * N )
	std::vector< TileData > m_Tiles;

	//	Map (Tile list) ( 4 bytes * M )
	std::vector< CMapData * > m_Maps;
};
