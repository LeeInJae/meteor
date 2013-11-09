#include "stdafx.h"
#include "Zone.h"


CZone::CZone(void)
{

}

CZone::CZone( std::wstring id )
	: m_ZoneId( id )
{

}

CZone::~CZone(void)
{
}

bool CZone::LoadZone()
{
	CZoneInfo * zoneInfo = new CZoneInfo( m_ZoneId );
	if( ! zoneInfo->LoadResource() )
	{
		wprintf_s(L"%s : LoadResource Fail\n", m_ZoneId);
		false;
	}
	ZoneHeader * header = zoneInfo->GetHeader();

	// header->mapType을 wstring으로 전환
	size_t originalLength = strlen(header->mapType) + 1;
	wchar_t *_Dest = new wchar_t[32];
	wmemset(_Dest, 0, 32);
	mbstowcs_s(NULL , _Dest, originalLength, header->mapType, _TRUNCATE);
	std::wstring mapType = _Dest;
	delete []_Dest;

	m_Map = new CZoneMap( mapType , header->mapNo );

	//std::list< ObjectData > * objects = zoneInfo->GetObjects();

	return true;
}