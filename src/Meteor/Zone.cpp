#include "stdafx.h"
#include "Zone.h"
#include "PC.h"


CZone::CZone(void)
{

}

CZone::CZone( std::wstring id )
	: m_ZoneId( id )
	, m_Map( nullptr )
{

}

CZone::~CZone(void)
{
	Release();
}


bool CZone::Update( float deltaTime, float x, float y )
{
	return m_Map->Update( x, y );
}


void CZone::Render()
{
	m_Map->Render();
	for ( auto object : m_Object )
		object->Render();
}


void CZone::Enter( CPC * player, CZone * from )
{
	player->SetPosition( 300.0f, 300.0f );
}


bool CZone::LoadZone()
{
	// TODO: Move this to ZoneInfo
	//CZoneInfo * zoneInfo = new CZoneInfo();
	//if( ! zoneInfo->LoadResource() )
	//{
	//	wprintf_s(L"%s : LoadResource Fail\n", m_ZoneId);
	//	false;
	//}
	////ZoneHeader * header = zoneInfo->GetHeader();

	//// header->mapType을 wstring으로 전환
	//size_t originalLength = strlen(header->mapType) + 1;
	//wchar_t *_Dest = new wchar_t[32];
	//wmemset(_Dest, 0, 32);
	//mbstowcs_s(NULL , _Dest, originalLength, header->mapType, _TRUNCATE);
	//std::wstring mapType = _Dest;
	//delete []_Dest;

	//m_Map = new CZoneMap( mapType , header->mapNo );

	////std::list< ObjectData > * objects = zoneInfo->GetObjects();

	return true;
}


// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CZone::Release()
{
	SafeDelete( m_Map );
	for ( auto object : m_Object )
		SafeDelete( object );
}
