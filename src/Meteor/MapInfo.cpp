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
bool CMapInfo::LoadResource( ResourceId id )
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

	UINT	colSize = m_Maps[0]->m_NumOfColumn;
	UINT	rowSize = m_Maps[0]->m_NumOfRow;

	map->SetSize( colSize, rowSize, 128.0f, 128.0f );

	for( UINT row = 0; row < rowSize; ++row )
	{
		for( UINT col = 0; col < colSize; ++col )
		{
			UINT tileNo = m_Maps[0]->m_Tiles[ row * colSize + col ].m_TileNo % 128;
			UINT treeNo = m_Maps[0]->m_Tiles[ row * colSize + col ].m_TileNo / 128;

			CD2DSprite * sprite = new CD2DSprite();
			CD2DBitmap * bitmap = static_cast<CD2DBitmap *>( CResourceManager::GetInstance().GetResource( m_Tiles[tileNo].m_FileName ) );

			sprite->SetBaseMatrix( D2D1::Matrix3x2F::Translation( col * 128.0f, row * 128.0f ) );
			sprite->SetImageWidth( bitmap->GetD2DBitmap()->GetSize().width );
			sprite->SetImageHeight( bitmap->GetD2DBitmap()->GetSize().width );
			sprite->SetBitmap( bitmap );

			map->AddSprite( row, sprite );

			if ( treeNo > 0 )
			{
				sprite = new CD2DSprite();
				bitmap = static_cast<CD2DBitmap *>( CResourceManager::GetInstance().GetResource( m_Tiles[treeNo].m_FileName ) );

				sprite->SetBaseMatrix( D2D1::Matrix3x2F::Translation( col * 128.0f, row * 128.0f ) );
				sprite->SetImageWidth( bitmap->GetD2DBitmap()->GetSize().width );
				sprite->SetImageHeight( bitmap->GetD2DBitmap()->GetSize().width );
				sprite->SetBitmap( bitmap );

				map->AddSprite( row, sprite );
			}
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
	const UINT COLUMN = 24;
	const UINT ROW = 16;

	m_MapId = L"map_village";

	SetTileSize( 128, 128 );

	AddTile( L"map_village_0000_1.png" );	// 0
	AddTile( L"map_village_0000_2.png" );
	AddTile( L"map_village_0000_3.png" );
	AddTile( L"map_village_0000_4.png" );

	AddTile( L"map_village_0001_1.png" );	// 4
	AddTile( L"map_village_0001_2.png" );
	AddTile( L"map_village_0001_3.png" );
	AddTile( L"map_village_0001_4.png" );

	AddTile( L"map_village_0010_1.png" );	// 8
	AddTile( L"map_village_0010_2.png" );
	AddTile( L"map_village_0010_3.png" );
	AddTile( L"map_village_0010_4.png" );

	AddTile( L"map_village_0011_1.png" );	// 12
	AddTile( L"map_village_0011_2.png" );
	AddTile( L"map_village_0011_3.png" );
	AddTile( L"map_village_0011_4.png" );

	AddTile( L"map_village_0100_1.png" );	// 16
	AddTile( L"map_village_0100_2.png" );
	AddTile( L"map_village_0100_3.png" );
	AddTile( L"map_village_0100_4.png" );

	AddTile( L"map_village_0101_1.png" );	// 20
	AddTile( L"map_village_0101_2.png" );
	AddTile( L"map_village_0101_3.png" );
	AddTile( L"map_village_0101_4.png" );

	AddTile( L"map_village_0111_1.png" );	// 24
	AddTile( L"map_village_0111_2.png" );
	AddTile( L"map_village_0111_3.png" );
	AddTile( L"map_village_0111_4.png" );

	AddTile( L"map_village_1000_1.png" );	// 28
	AddTile( L"map_village_1000_2.png" );
	AddTile( L"map_village_1000_3.png" );
	AddTile( L"map_village_1000_4.png" );

	AddTile( L"map_village_1010_1.png" );	// 32
	AddTile( L"map_village_1010_2.png" );
	AddTile( L"map_village_1010_3.png" );
	AddTile( L"map_village_1010_4.png" );

	AddTile( L"map_village_1011_1.png" );	// 36
	AddTile( L"map_village_1011_2.png" );
	AddTile( L"map_village_1011_3.png" );
	AddTile( L"map_village_1011_4.png" );

	AddTile( L"map_village_1100_1.png" );	// 40
	AddTile( L"map_village_1100_2.png" );
	AddTile( L"map_village_1100_3.png" );
	AddTile( L"map_village_1100_4.png" );

	AddTile( L"map_village_1101_1.png" );	// 44
	AddTile( L"map_village_1101_2.png" );
	AddTile( L"map_village_1101_3.png" );
	AddTile( L"map_village_1101_4.png" );

	AddTile( L"map_village_1110_1.png" );	// 48
	AddTile( L"map_village_1110_2.png" );
	AddTile( L"map_village_1110_3.png" );
	AddTile( L"map_village_1110_4.png" );

	AddTile( L"map_village_1111_1.png" );	// 52
	AddTile( L"map_village_1111_2.png" );
	AddTile( L"map_village_1111_3.png" );
	AddTile( L"map_village_1111_4.png" );

	AddTile( L"map_tree_0011.png" );	// 56
	AddTile( L"map_tree_0101.png" );	// 57
	AddTile( L"map_tree_0111.png" );	// 58
	AddTile( L"map_tree_1010.png" );	// 59
	AddTile( L"map_tree_1011.png" );	// 60
	AddTile( L"map_tree_1100.png" );	// 61
	AddTile( L"map_tree_1101.png" );	// 62
	AddTile( L"map_tree_1110.png" );	// 63
	AddTile( L"map_tree_1111.png" );	// 64

	CreateMapData( COLUMN, ROW );

	UINT fildTileNo[ROW][COLUMN] = {
		{ 0, 0, 0, 0, 25, 37, 11, 16, 40, 28, 7, 24, 39, 12, 14, 15, 25, 33, 16, 42, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 53, 49, 28, 7, 10, 2, 22, 55, 48, 42, 42, 42, 47, 32, 7, 15, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 48, 28, 1, 23, 32, 0, 21, 50, 28, 0, 7, 8, 18, 30, 23, 55, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 38, 15, 9, 17, 28, 1, 21, 34, 0, 0, 21, 37, 10, 2, 19, 47, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 51, 41, 29, 2, 6, 15, 26, 34, 6, 11, 21, 49, 29, 1, 3, 21, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 38, 12, 14, 10, 22, 51, 43, 28, 16, 31, 18, 31, 6, 15, 9, 20, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 42, 41, 46, 35, 21, 33, 1, 2, 1, 0, 0, 5, 26, 48, 31, 19, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 4, 9, 22, 39, 24, 35, 5, 9, 0, 1, 3, 17, 45, 33, 5, 9, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 19, 28, 17, 43, 42, 28, 20, 32, 0, 5, 13, 12, 24, 36, 25, 39, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 5, 10, 7, 8, 3, 22, 39, 9, 23, 51, 41, 46, 55, 53, 52, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 33, 23, 37, 26, 39, 8, 19, 43, 28, 16, 29, 0, 17, 46, 53, 55, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 39, 24, 48, 46, 50, 31, 1, 5, 13, 14, 12, 15, 12, 27, 54, 50, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 43, 42, 31, 17, 28, 4, 14, 25, 48, 46, 50, 44, 54, 51, 43, 30, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 9, 3, 3, 0, 1, 19, 41, 43, 30, 18, 31, 18, 42, 30, 3, 4, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 28, 1, 1, 3, 5, 15, 14, 14, 10, 5, 11, 2, 2, 5, 15, 27, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 11, 7, 15, 12, 27, 51, 42, 42, 31, 17, 31, 0, 4, 26, 51, 43, 0, 0, 0, 0 }
	};

	UINT treeTileNo[ROW][COLUMN] = {
		{ 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 63, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 62, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 60, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 58, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64 },
		{ 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64 }
	};

	UINT fildMovement[ROW][COLUMN] = {
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF },
		{ 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF, 0xF }
	};

	for ( UINT row = 0; row < ROW; ++row )
	{
		for ( UINT col = 0; col < COLUMN; ++col )
		{
			m_Maps[0]->m_Tiles[row * COLUMN + col].m_TileNo		= fildTileNo[row][col] + treeTileNo[row][col] * 128;
			m_Maps[0]->m_Tiles[row * COLUMN + col].m_Movement	= fildMovement[row][col];
		}
	}

	for ( UINT row = 0; row < ROW; ++row )
	{
		printf( "{" );
		for ( UINT col = 0; col < COLUMN; ++col )
		{
			if ( col != 0 )
				printf(",");

			printf( " %d", m_Maps[0]->m_Tiles[row * COLUMN + col].m_TileNo );
		}
		printf( " },\n" );
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
