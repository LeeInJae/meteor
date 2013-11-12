#include "stdafx.h"
#include "MapInfo.h"
#include "ZoneMap.h"
#include "Sprite.h"
#include "ResourceManager.h"

// for srand
#include <time.h>

// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CMapInfo::CMapInfo()
{
	m_Header.m_MapCount		= 0;
	m_Header.m_TileCount	= 0;
	m_Header.m_TileWidth	= 0;
	m_Header.m_TileHeight	= 0;
}


// ----------------------------------------------------------------
//	Destrutor
// ----------------------------------------------------------------
CMapInfo::~CMapInfo(void)
{
}


// ----------------------------------------------------------------
//	LoadResource
// ----------------------------------------------------------------
bool CMapInfo::LoadResource( ResourceId mapId )
{
	// TODO: Restore original code.
	SampleData();

	// TODO: Original code.
	//HANDLE	hFile;
	//DWORD	dwBytesRead = 0;
	//DWORD	dwBytesWrite = 0;
	//std::wstring filePath = m_MapType + L".map";

	//hFile = CreateFile( filePath.c_str(),	// file to open
	//	GENERIC_READ,				// open for reading
	//	FILE_SHARE_READ,			// share for reading
	//	NULL,						// default security
	//	OPEN_EXISTING,				// existing file only
	//	FILE_ATTRIBUTE_NORMAL,		// normal file
	//	NULL);						// no attr. template

	//if ( hFile == INVALID_HANDLE_VALUE )
	//{
	//	wprintf( L"Error: unable to open file \"%s\" for read.\n", filePath.c_str() );
	//	return false;
	//}

	//if ( FALSE == ReadFile( hFile, &m_Header, sizeof(m_Header), &dwBytesRead, NULL ) ||
	//	dwBytesRead < sizeof(m_Header) )
	//{
	//	wprintf( L"Error: Unable to read from file.\n" );
	//	CloseHandle(hFile);
	//	return false;
	//}

	//for ( UINT count = 0; count < m_Header.m_TileCount; ++count )
	//{
	//	TileData tileData;

	//	if ( FALSE == ReadFile( hFile, &tileData, sizeof(tileData), &dwBytesRead, NULL ) ||
	//		dwBytesRead < sizeof(tileData) )
	//	{
	//		wprintf( L"Error: Unable to read from file.\n" );
	//		CloseHandle(hFile);
	//		return false;
	//	}

	//	m_Tiles.push_back( tileData );
	//}

	//for ( UINT count = 0; count < m_Header.m_MapCount; ++count )
	//{
	//	CMapData * mapData = new CMapData();
	//	mapData->Read( hFile );

	//	m_Maps.push_back( mapData );
	//}

	//CloseHandle( hFile );

	return true;
}


// ----------------------------------------------------------------
//	CreateMap
// ----------------------------------------------------------------
CZoneMap * CMapInfo::CreateMap()
{
	CZoneMap * map = new CZoneMap();

	UINT	rowSize = m_Maps[0]->m_NumOfColumn;
	UINT	colSize = m_Maps[0]->m_NumOfRow;

	map->SetSize( rowSize, colSize );

	for( UINT row = 0; row < rowSize; ++row )
	{
		for( UINT col = 0; col < colSize; ++col )
		{
			UINT tileNo = m_Maps[0]->m_Tiles[ row * rowSize + col ].m_TileNo;
			CD2DSprite * sprite = new CD2DSprite();
			CD2DBitmap * bitmap = static_cast<CD2DBitmap *>( CResourceManager::GetInstance().GetResource( m_Tiles[tileNo].m_FileName ) );

			sprite->m_BaseMatrix	= D2D1::Matrix3x2F::Translation( col * 128.0f, row * 128.0f );
			sprite->m_ImageWidth	= bitmap->GetD2DBitmap()->GetSize().width;
			sprite->m_ImageHeight	= bitmap->GetD2DBitmap()->GetSize().width;
			sprite->m_pD2DBitmap	= bitmap;

			map->AddSprite( row, sprite );
		}
	}

	return map;
}


// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CMapInfo::Release()
{
	for ( auto map : m_Maps )
		delete map;

	CResourceManager::GetInstance().ReleaseResource(this);
}


// ----------------------------------------------------------------
//	SampleData
// ----------------------------------------------------------------
void CMapInfo::SampleData()
{
	const UINT COLUMN = 16;
	const UINT ROW = 16;

	m_MapId = L"map_village";

	SetTileSize( 128, 128 );

	AddTile( L"map_village_0000_1.png" );
	AddTile( L"map_village_0000_2.png" );
	AddTile( L"map_village_0000_3.png" );
	AddTile( L"map_village_0000_4.png" );

	AddTile( L"map_village_0001_1.png" );
	AddTile( L"map_village_0001_2.png" );
	AddTile( L"map_village_0001_3.png" );
	AddTile( L"map_village_0001_4.png" );

	AddTile( L"map_village_0010_1.png" );
	AddTile( L"map_village_0010_2.png" );
	AddTile( L"map_village_0010_3.png" );
	AddTile( L"map_village_0010_4.png" );

	AddTile( L"map_village_0011_1.png" );
	AddTile( L"map_village_0011_2.png" );
	AddTile( L"map_village_0011_3.png" );
	AddTile( L"map_village_0011_4.png" );

	AddTile( L"map_village_0100_1.png" );
	AddTile( L"map_village_0100_2.png" );
	AddTile( L"map_village_0100_3.png" );
	AddTile( L"map_village_0100_4.png" );

	AddTile( L"map_village_0101_1.png" );
	AddTile( L"map_village_0101_2.png" );
	AddTile( L"map_village_0101_3.png" );
	AddTile( L"map_village_0101_4.png" );

	AddTile( L"map_village_0111_1.png" );
	AddTile( L"map_village_0111_2.png" );
	AddTile( L"map_village_0111_3.png" );
	AddTile( L"map_village_0111_4.png" );

	AddTile( L"map_village_1000_1.png" );
	AddTile( L"map_village_1000_2.png" );
	AddTile( L"map_village_1000_3.png" );
	AddTile( L"map_village_1000_4.png" );

	AddTile( L"map_village_1010_1.png" );
	AddTile( L"map_village_1010_2.png" );
	AddTile( L"map_village_1010_3.png" );
	AddTile( L"map_village_1010_4.png" );

	AddTile( L"map_village_1011_1.png" );
	AddTile( L"map_village_1011_2.png" );
	AddTile( L"map_village_1011_3.png" );
	AddTile( L"map_village_1011_4.png" );

	AddTile( L"map_village_1100_1.png" );
	AddTile( L"map_village_1100_2.png" );
	AddTile( L"map_village_1100_3.png" );
	AddTile( L"map_village_1100_4.png" );

	AddTile( L"map_village_1101_1.png" );
	AddTile( L"map_village_1101_2.png" );
	AddTile( L"map_village_1101_3.png" );
	AddTile( L"map_village_1101_4.png" );

	AddTile( L"map_village_1110_1.png" );
	AddTile( L"map_village_1110_2.png" );
	AddTile( L"map_village_1110_3.png" );
	AddTile( L"map_village_1110_4.png" );

	AddTile( L"map_village_1111_1.png" );
	AddTile( L"map_village_1111_2.png" );
	AddTile( L"map_village_1111_3.png" );
	AddTile( L"map_village_1111_4.png" );

	CreateMapData( COLUMN, ROW );

	srand((UINT)time(nullptr));

	for ( UINT col = 0; col < COLUMN; ++col )
	{
		for ( UINT row = 0; row < ROW; ++row )
		{
			UINT tileNo;
			UINT movement = 6;
			while ( movement == 6 || movement == 9 )
			{
				movement = rand() % 0x10;
#define TOPLEFT(movement)		(( movement & 0x8 ) >> 3)
#define TOPRIGHT(movement)		(( movement & 0x4 ) >> 2)
#define BOTTOMLEFT(movement)	(( movement & 0x2 ) >> 1)
#define BOTTOMRIGHT(movement)	(( movement & 0x1 ))
				if ( row > 0 )
				{
					UINT upper = m_Maps[0]->m_Tiles[(row-1) * COLUMN + col].m_Movement;
					if ( TOPLEFT(movement) != BOTTOMLEFT(upper) )
						movement ^= 1 << 3;
					if ( TOPRIGHT(movement) != BOTTOMRIGHT(upper) )
						movement ^= 1 << 2;
				}

				if ( col > 0 )
				{
					UINT left = m_Maps[0]->m_Tiles[row * COLUMN + col - 1].m_Movement;
					if ( TOPLEFT(movement) != TOPRIGHT(left) )
						movement ^= 1 << 3;
					if ( BOTTOMLEFT(movement) != BOTTOMRIGHT(left) )
						movement ^= 1 << 1;
				}
			}

			switch ( movement )
			{
			case 0x0:
				tileNo = rand() % 4;
				break;
			case 0x1:
				tileNo = 1 * 4 + rand() % 4;
				break;
			case 0x2:
				tileNo = 2 * 4 + rand() % 4;
				break;
			case 0x3:
				tileNo = 3 * 4 + rand() % 4;
				break;
			case 0x4:
				tileNo = 4 * 4 + rand() % 4;
				break;
			case 0x5:
				tileNo = 5 * 4 + rand() % 4;
				break;
			case 0x6:
				tileNo = 0xBAB0;
				break;	// Should not reach here
			case 0x7:
				tileNo = 6 * 4 + rand() % 4;
				break;
			case 0x8:
				tileNo = 7 * 4 + rand() % 4;
				break;
			case 0x9:
				tileNo = 0xBAB0;
				break;	// Should not reach here
			case 0xA:
				tileNo = 8 * 4 + rand() % 4;
				break;
			case 0xB:
				tileNo = 9 * 4 + rand() % 4;
				break;
			case 0xC:
				tileNo = 10 * 4 + rand() % 4;
				break;
			case 0xD:
				tileNo = 11 * 4 + rand() % 4;
				break;
			case 0xE:
				tileNo = 12 * 4 + rand() % 4;
				break;
			case 0xF:
				tileNo = 13 * 4 + rand() % 4;
				break;
			default:
				tileNo = 0xBAB0;
				break;	// Should not reach here
			}

			m_Maps[0]->m_Tiles[row * COLUMN + col].m_TileNo = tileNo;
			m_Maps[0]->m_Tiles[row * COLUMN + col].m_Movement = movement;
		}
	}
}


// ----------------------------------------------------------------
//	SetTileSize
// ----------------------------------------------------------------
void CMapInfo::SetTileSize( UINT tileWidth, UINT tileHeight )
{
	m_Header.m_TileWidth = tileWidth;
	m_Header.m_TileHeight = tileHeight;
}


// ----------------------------------------------------------------
//	AddTile
// ----------------------------------------------------------------
void CMapInfo::AddTile( std::wstring fileName )
{
	TileData tileData;
	wcscpy_s( tileData.m_FileName, fileName.c_str() );
	m_Tiles.push_back( tileData );
}


// ----------------------------------------------------------------
//	SetSize
// ----------------------------------------------------------------
void CMapInfo::CreateMapData( UINT column, UINT row )
{
	CMapData * mapData = new CMapData();

	mapData->m_NumOfColumn = column;
	mapData->m_NumOfRow = row;

	for( UINT r = 0; r < row; ++r )
	{
		for( UINT c = 0; c < column; ++c )
		{
			Tile tile = { 0, 0xFFFF };
			mapData->m_Tiles.push_back( tile );
		}
	}

	m_Maps.push_back( mapData );
}


// ----------------------------------------------------------------
//	SaveResource
// ----------------------------------------------------------------
bool CMapInfo::SaveResource( std::wstring fileName )
{
	return false;
}
