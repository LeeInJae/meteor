#include "stdafx.h"
#include "ZoneInfo.h"
#include "Zone.h"
#include "MapInfo.h"
#include "Monster.h"
#include "ResourceManager.h"

// for srand
#include <time.h>

CZoneInfo::CZoneInfo()
{
}


CZoneInfo::~CZoneInfo(void)
{
}

//  Zone ������ ���� �ε�
bool CZoneInfo::LoadResource( ResourceId id )
{
	// TODO: Restore original code.

	// TODO: Original code.
	//HANDLE	hFile;
	//DWORD	dwBytesRead = 0;
	//DWORD	dwBytesWrite = 0;
	//std::wstring filePath = zoneId + L".zone";

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

	//for ( UINT count = 0; count < m_Header.numOfObject; ++count )
	//{
	//	ObjectData objectData;

	//	if ( FALSE == ReadFile( hFile, &objectData, sizeof(objectData), &dwBytesRead, NULL ) ||
	//		dwBytesRead < sizeof(objectData) )
	//	{
	//		wprintf( L"Error: Unable to read from file.\n" );
	//		CloseHandle(hFile);
	//		return false;
	//	}

	//	m_Objects.push_back( objectData );
	//}

	//CloseHandle( hFile );

	return true;
}


CZone * CZoneInfo::CreateZone()
{
	CZone * zone = new CZone();

	CMapInfo * mapInfo = CResourceManager::GetInstance().GetMapInfo( L"map_village" );
	zone->SetMap( mapInfo->CreateMap() );
	//SafeRelease( mapInfo );
	/*
	CMonster * monster = new CMonster( L"skeleton_mage" );
	monster->LoadAnimation();
	monster->SetPosition( 150, 150 );
	monster->SetDirection( RIGHT );
	zone->AddObject( monster );
	*/

	// ���� ���� ��ġ
	const int numOfMonster = 10;
	const int marginMonster = 40;
	srand((UINT)time(nullptr));
	float monsterPosX[numOfMonster];
	float monsterPosY[numOfMonster];
	for (int i = 0; i < numOfMonster; ++i){
		monsterPosX[i] = float( rand() % ( 16 * 128 - 128 ) + 64 );
		monsterPosY[i] = monsterPosX[i];
		
		for (int j = 0; j < i; ++j){
			if (monsterPosX[j] - marginMonster < monsterPosX[i] &&
				monsterPosX[j] + marginMonster > monsterPosX[i] &&
				monsterPosY[j] - marginMonster < monsterPosY[i] &&
				monsterPosY[j] + marginMonster > monsterPosY[i] )
			{
				--i;
				break;
			}
		}
	}
	for (int i = 0; i < numOfMonster; ++i)
	{
		CMonster * monster = new CMonster( L"skeleton_mage" );
		monster->LoadAnimation();
		monster->SetPosition( monsterPosX[i], monsterPosY[i] );
		monster->SetDirection( RIGHT );
		monster->SetHp( 5.0f );
		monster->SetMaxHp( 5.0f );
		zone->AddObject( monster );
	}

	SafeRelease( mapInfo );
	return zone;
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
