#include "stdafx.h"
#include "MapInfo.h"


// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CMapInfo::CMapInfo( std::wstring mapType )
	: m_MapType( mapType )
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
bool CMapInfo::LoadResource()
{
	HANDLE	hFile;
	DWORD	dwBytesRead = 0;
	DWORD	dwBytesWrite = 0;
	std::wstring filePath = m_MapType + L".map";

	hFile = CreateFile( filePath.c_str(),	// file to open
		GENERIC_READ,				// open for reading
		FILE_SHARE_READ,			// share for reading
		NULL,						// default security
		OPEN_EXISTING,				// existing file only
		FILE_ATTRIBUTE_NORMAL,		// normal file
		NULL);						// no attr. template

	if ( hFile == INVALID_HANDLE_VALUE )
	{
		wprintf( L"Error: unable to open file \"%s\" for read.\n", filePath.c_str() );
		return false;
	}

	if ( FALSE == ReadFile( hFile, &m_Header, sizeof(m_Header), &dwBytesRead, NULL ) ||
		dwBytesRead < sizeof(m_Header) )
	{
		wprintf( L"Error: Unable to read from file.\n" );
		CloseHandle(hFile);
		return false;
	}

	for ( UINT count = 0; count < m_Header.m_TileCount; ++count )
	{
		TileData tileData;

		if ( FALSE == ReadFile( hFile, &tileData, sizeof(tileData), &dwBytesRead, NULL ) ||
			dwBytesRead < sizeof(tileData) )
		{
			wprintf( L"Error: Unable to read from file.\n" );
			CloseHandle(hFile);
			return false;
		}

		m_Tiles.push_back( tileData );
	}

	for ( UINT count = 0; count < m_Header.m_MapCount; ++count )
	{
		CMapData * mapData = new CMapData();
		mapData->Read( hFile );

		m_Maps.push_back( mapData );
	}

	CloseHandle( hFile );

	return true;
}

// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CMapInfo::Release()
{
	for ( auto map : m_Maps )
		delete map;
}