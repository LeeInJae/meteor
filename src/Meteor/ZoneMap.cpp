#include "stdafx.h"
#include "ZoneMap.h"


CZoneMap::CZoneMap( std::wstring mapType, UINT mapNo )
	: m_MapType( mapType )
	, m_MapNo( mapNo )
{
}

CZoneMap::~CZoneMap(void)
{
}

bool CZoneMap::LoadMap()
{
	// TODO:
	//	vector<Sprite &> sprites = ResourceManager::GetInstance().GetSprite( m_MapInfo );

	CMapInfo mapInfo ( m_MapType );
	MapHeader mapHeader = mapInfo.GetHeader();
	m_MapData = mapInfo.GetMapData( m_MapNo );

	/*
	m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_LEFT_01.png" ) );
	m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_LEFT_02.png" ) );
	m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_LEFT_03.png" ) );
	m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_RIGHT_01.png" ) );
	m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_RIGHT_02.png" ) );
	m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_RIGHT_03.png" ) );
	m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_UP_01.png" ) );
	m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_UP_02.png" ) );
	m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_UP_03.png" ) );
	m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_DOWN_01.png" ) );
	m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_DOWN_02.png" ) );
	m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_DOWN_03.png" ) );
	*/
	return true;
}

bool CZoneMap::Render()
{
	return false;
}
