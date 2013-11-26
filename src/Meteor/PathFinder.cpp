#include "stdafx.h"
#include "PathFinder.h"

#include <algorithm>
#include <deque>
#include <cmath>
#include <assert.h>

// Debug
#include <iostream>

CPathFinder::CPathFinder(void)
	: m_SizeX( 0 )
	, m_SizeY( 0 )
{
}


CPathFinder::~CPathFinder(void)
{
}


void CPathFinder::ResetMap( int sizeX, int sizeY )
{
	m_SizeX = sizeX;
	m_SizeY = sizeY;

	m_Grids.resize( sizeX );
	for ( int x = 0; x < sizeX; ++x )
	{
		m_Grids[x].resize( sizeY );
		for ( int y = 0; y < sizeY; ++y )
			m_Grids[x][y] = true;
	}
}


void CPathFinder::AddObject( int leftX, int rightX, int topY, int bottomY )
{
	assert( leftX >= 0 );
	assert( rightX >= 0 );
	assert( topY >= 0 );
	assert( bottomY >= 0 );
	assert( leftX < m_SizeX );
	assert( rightX < m_SizeX );
	assert( topY < m_SizeY );
	assert( bottomY < m_SizeY );
	assert( leftX <= rightX );
	assert( topY <= bottomY );

	for ( int x = leftX; x <= rightX; ++x )
		for ( int y = topY; y <= bottomY; ++y )
			m_Grids[x][y] = false;
}


Direction CPathFinder::FindPath( int startX, int startY, int targetX, int targetY )
{
	CPathNode start( nullptr, 1, startX, startY, targetX, targetY );
	CPathNode target( nullptr, 1, targetX, targetY, targetX, targetY );
	assert( start != target );

	m_OpenedNodes.insert( &start );

	while ( m_OpenedNodes.size() > 0 )
	{
		auto iter = m_OpenedNodes.begin();
		CPathNode * current = *iter;
		m_OpenedNodes.erase( iter );

		if ( *current == target )
		{
			target.SetParent( current );
			break;
		}

		std::vector< CPathNode * > around;
		for ( int i = -1; i <= 1; ++i )
		{
			for ( int j = -1; j <= 1; ++j )
			{
				int x = current->GetX() + i;
				int y = current->GetY() + j;
				if ( GetGrid( x, y ) )
					around.push_back( new CPathNode( current, ( i * i + j * j ), x, y, targetX, targetY ) );
			}
		}

		for ( auto next : around )
		{
			assert ( current != next );		// Should be stop here!

			// Search opened
			auto foundOpen = m_OpenedNodes.find( next );

			if ( foundOpen != m_OpenedNodes.end() && *foundOpen <= next )
			{
				delete next;
				continue;
			}
			else
				m_OpenedNodes.erase( next );

			// Search closed
			auto foundClose = m_ClosedNodes.find( next );

			if ( foundClose != m_ClosedNodes.end() && *foundClose <= next )
			{
				delete next;
				continue;
			}
			else
				m_ClosedNodes.erase( next );

			m_OpenedNodes.insert( next );
		}

		m_ClosedNodes.insert( current );
	}

	//// Debug
	//for ( int x = 0; x < m_SizeX; ++x )
	//{
	//	for ( int y = 0; y < m_SizeY; ++y )
	//		std::cout << ( ( x == startX && y == startY ) ? "@" : ( m_Grids[x][y] ? " " : "X" ) );
	//	std::cout << std::endl;
	//}

	if ( target.GetParent() == nullptr )
		return NONE;

	CPathNode * node = &target;
	while ( node->GetParent() != &start && node->GetParent() != nullptr )
	{
		node = node->GetParent();
	}

	return GetDirection( startX, startY, node->GetX(), node->GetY() );
}


CPathFinder::CPathNode::CPathNode( CPathNode * parent, int g, int x, int y, int targetX, int targetY )
	: m_Parent( parent )
	, m_G( g )
	, m_X( x )
	, m_Y( y )
{
	if ( parent )
		m_G += parent->m_G;
	SetHuristic( targetX, targetY );
}


void CPathFinder::CPathNode::SetHuristic( int targetX, int targetY )
{
	int deltaX = targetX - m_X;
	int deltaY = targetY - m_Y;
	m_H = ( deltaX * deltaX ) + ( deltaY * deltaY );
}



bool CPathFinder::GetGrid( int x, int y )
{
	if ( x < 0 || y < 0 || x >= m_SizeX || y >= m_SizeY ) return false;

	return m_Grids[x][y];
}
