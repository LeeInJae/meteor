#include "stdafx.h"
#include "MapInfo.h"
#include "ZoneMap.h"
#include "Sprite.h"
#include "ResourceManager.h"


// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CMapInfo::CMapInfo()
{
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
	m_Header.m_MapCount = 1;
	m_Header.m_TileCount = 1;
	m_Header.m_TileWidth = 128;
	m_Header.m_TileHeight = 128;

	TileData tileData;
	tileData.m_TileX = 0.0f;
	tileData.m_TileY = 0.0f;
	m_Tiles.push_back( tileData );

	CMapData * mapData = new CMapData();
	mapData->m_NumOfColumn = 5;
	mapData->m_NumOfRow = 4;

	for( int row = 0; row < 4; ++row )
	{
		for( int col = 0; col < 5; ++col )
		{
			Tile tile = { 0, 0xFFFF };
			mapData->m_Tiles.push_back( tile );
		}
	}

	m_Maps.push_back( mapData );

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

	map->SetSize( 5, 4 );

	for( int row = 0; row < 4; ++row )
	{
		for( int col = 0; col < 5; ++col )
		{
			CD2DSprite * sprite = new CD2DSprite();
			CD2DBitmap * bitmap = ( ( row + col ) % 3 == 0 )
				? static_cast<CD2DBitmap *>( CResourceManager::GetInstance().GetResource( L"test_tile.png" ) )
				: static_cast<CD2DBitmap *>( CResourceManager::GetInstance().GetResource( L"test_tile2.png" ) );

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