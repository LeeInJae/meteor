#include "stdafx.h"
#include "ZoneInfo.h"


CZoneInfo::CZoneInfo( std::wstring zoneId )
	: m_ZoneId( zoneId )
{
}


CZoneInfo::~CZoneInfo(void)
{
}

//  Zone 데이터 파일 로드
bool CZoneInfo::LoadResource()
{
	HANDLE	hFile;
	DWORD	dwBytesRead = 0;
	DWORD	dwBytesWrite = 0;
	std::wstring filePath = m_ZoneId + L".zone";

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

	for ( UINT count = 0; count < m_Header.numOfObject; ++count )
	{
		ObjectData objectData;

		if ( FALSE == ReadFile( hFile, &objectData, sizeof(objectData), &dwBytesRead, NULL ) ||
			dwBytesRead < sizeof(objectData) )
		{
			wprintf( L"Error: Unable to read from file.\n" );
			CloseHandle(hFile);
			return false;
		}

		m_Objects.push_back( objectData );
	}

	CloseHandle( hFile );

	return true;
}

void CZoneInfo::Release()
{

}

bool CZoneInfo::LoadMap()
{
	return false;
}

bool CZoneInfo::LoadObjects()
{
	return false;
}
