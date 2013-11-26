#include "stdafx.h"

#include "Sprite.h"
#include "ZoneMap.h"
#include "MapInfo.h"

CZoneMap::CZoneMap()
	: m_SizeX(0)
	, m_SizeY(0)
	, m_Width(0.0f)
	, m_Height(0.0f)
{
}

CZoneMap::~CZoneMap(void)
{
}

// ----------------------------------------------------------------
//	SetSize
// ----------------------------------------------------------------
void CZoneMap::SetSize( UINT x, UINT y, float width, float height )
{
	m_SizeX = x;
	m_SizeY = y;
	m_Width = x * width;
	m_Height = y * height;

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

	return true;
}


// ----------------------------------------------------------------
//	CanMove
// ----------------------------------------------------------------
Direction CZoneMap::FindPath( const CGameObject * monster, const CGameObject * target, const std::list< CGameObject * > objects )
{
	return NONE;
	//float monsterSize = monster->GetBoundary().GetRadius();

	//// Grid size : 128 * 128
	//int sizeX = static_cast<int>( ( m_Width ) / 128 );
	//int sizeY = static_cast<int>( ( m_Height ) / 128 );
	////int sizeX = static_cast<int>( ( m_SizeX * m_Width ) / 64 );
	////int sizeY = static_cast<int>( ( m_SizeY * m_Height ) / 64 );

	//// Clear new map
	//m_PathFinder.ResetMap( sizeX, sizeY );

	//// Mark all blocking object
	//for ( auto object : objects )
	//{
	//	if ( object == monster ) continue;
	//	if ( object == target ) continue;

	//	Position position = object->GetPosition();
	//	int size = static_cast<int>( monsterSize + object->GetBoundary().GetRadius() ) / 128;
	//	int x = static_cast<int>( position.x + 32 ) / 128;
	//	int y = static_cast<int>( position.y + 32 ) / 128;

	//	if ( size <= 0 ) size = 1;
	//	if ( x < size ) x = size;
	//	if ( y < size ) y = size;

	//	m_PathFinder.AddObject( x - size, x + size, y - size, y + size );
	//	//std::cout << "(" << x - size << ", " << x + size << ", " << y - size << ", " << y + size << " )" << std::endl;
	//}

	//// Start finding
	//Position monsterPosition = monster->GetPosition();
	//Position targetPosition = target->GetPosition();
	//int monsterX = static_cast<int>( monsterPosition.x + 32 ) / 128;
	//int monsterY = static_cast<int>( monsterPosition.y + 32 ) / 128;
	//int targetX = static_cast<int>( targetPosition.x + 32 ) / 128;
	//int targetY = static_cast<int>( targetPosition.y + 32 ) / 128;

	//return m_PathFinder.FindPath( monsterX, monsterY, targetX, targetY );
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
