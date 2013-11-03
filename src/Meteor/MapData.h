#pragma once

#include <windows.h>
#include <vector>

// ----------------------------------------------------------------
//	Tile
// ----------------------------------------------------------------
struct Tile
{
	UINT	m_TileNo;
	UINT	m_Movement;
};

// ----------------------------------------------------------------
//	CMapData
// ----------------------------------------------------------------
class CMapData
{
public:
	CMapData(void);
	~CMapData(void);

	bool Read( HANDLE hFile );
	bool Write( HANDLE hFile );

	UINT	m_NumOfColumn;
	UINT	m_NumOfRow;
	std::vector<Tile> m_Tiles;
};

