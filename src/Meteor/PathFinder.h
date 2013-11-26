#pragma once

#include "GameObject.h"
#include <set>
#include <functional>

template< typename Type >
class Compare : public std::binary_function< Type, Type, bool >
{
public:
	bool operator() ( Type& lhs, Type& rhs ) const
	{
		return (*lhs) < (*rhs);
	}
};

class CPathFinder
{
public:
	CPathFinder(void);
	~CPathFinder(void);

	void ResetMap( int sizeX, int sizeY );
	void AddObject( int leftX, int rightX, int topY, int bottomY );
	Direction FindPath( int startX, int startY, int targetX, int targetY );

protected:
	class CPathNode
	{
	public:
		CPathNode( CPathNode * parent, int g, int x, int y, int targetX, int targetY );

		void SetParent( CPathNode * parent ) { m_Parent = parent; }
		void SetHuristic( int targetX, int targetY );
		int GetX() const { return m_X; }
		int GetY() const { return m_Y; }
		CPathNode * GetParent() const { return m_Parent; }
		int TotalCost() const { return m_G + m_H; }
		std::vector< CPathNode * > GetAround();

		bool operator== ( const CPathNode & rhs ) const { return ( m_X == rhs.m_X ) && ( m_Y == rhs.m_Y ); }
		bool operator!= ( const CPathNode & rhs ) const { return ( m_X != rhs.m_X ) || ( m_Y != rhs.m_Y ); }
		bool operator< ( const CPathNode & rhs ) const { return TotalCost() < rhs.TotalCost(); }
		bool operator> ( const CPathNode & rhs ) const { return TotalCost() > rhs.TotalCost(); }

	protected:
		CPathNode *	m_Parent;
		int			m_G, m_H;
		int			m_X, m_Y;
	};

	bool GetGrid( int x, int y );

	int									m_SizeX;
	int									m_SizeY;
	std::vector< std::vector< bool > >	m_Grids;
	std::vector< CPathNode >			m_PathNodes;
	std::set< CPathNode *, Compare< CPathNode * const > > m_OpenedNodes;
	std::set< CPathNode *, Compare< CPathNode * const > > m_ClosedNodes;
};
