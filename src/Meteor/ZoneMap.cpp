#include "stdafx.h"

#include "Sprite.h"
#include "ZoneMap.h"
#include "MapInfo.h"

CZoneMap::CZoneMap()
{
}

CZoneMap::~CZoneMap(void)
{
}

// ----------------------------------------------------------------
//	SetSize
// ----------------------------------------------------------------
void CZoneMap::SetSize( UINT x, UINT y )
{
	m_SizeX = x;
	m_SizeY = y;

	std::vector<CSprite *> row;
	for ( UINT i = 0; i < x; ++i )
		m_Sprites.push_back( row );
}


// ----------------------------------------------------------------
//	AddSprite
// ----------------------------------------------------------------
void CZoneMap::AddSprite( int row, CSprite * sprite )
{
	m_Sprites[row].push_back( sprite );
}


// ----------------------------------------------------------------
//	Update
// ----------------------------------------------------------------
bool CZoneMap::Update( Position & playerPosition )
{
	m_Position.x = -playerPosition.x;
	m_Position.y = -playerPosition.y;
	m_Position.mode = BASE_TOPLEFT;

	return true;
}


// ----------------------------------------------------------------
//	Render
// ----------------------------------------------------------------
void CZoneMap::Render()
{
	for ( auto & row : m_Sprites )
	{
		for ( auto sprite : row )
		{
			sprite->SetPosition( m_Position );
			sprite->Render();
		}
	}
}


// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CZoneMap::Release()
{
	for ( auto & row : m_Sprites )
		for ( auto sprite : row )
			SafeRelease( sprite );

	m_Sprites.clear();
}
