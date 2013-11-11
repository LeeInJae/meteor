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
bool CZoneMap::Update( float x, float y )
{
	m_PositionX = x;
	m_PositionY = y;

	return true;
}


// ----------------------------------------------------------------
//	Render
// ----------------------------------------------------------------
void CZoneMap::Render()
{
	Position position = { 512.0f - m_PositionX, 384.0f - m_PositionY, BASE_TOPLEFT, DOWN };
	for ( auto & row : m_Sprites )
	{
		for ( auto sprite : row )
		{
			sprite->SetPosition( position );
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
