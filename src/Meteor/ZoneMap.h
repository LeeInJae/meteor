#pragma once

#include "IResource.h"
#include "Position.h"
#include <vector>
#include <string>

class CSprite;
class CMapInfo;
class CMapData;

// ================================================================
//	CZoneMap
// ================================================================
class CZoneMap
{
public:
	CZoneMap();
	~CZoneMap(void);

	void SetSize( UINT x, UINT y, float width, float height );
	void AddSprite( int row, CSprite * sprite );
	bool Update( Position & playerPosition );
	void Render();

	bool CanMove( const Position & position ) const; // �ش� ��ǥ�� �̵� ���� ����

	// --------------------------------
	//	IResource interface
	// --------------------------------
	void Release();

private:
	UINT					m_SizeX;
	UINT					m_SizeY;
	float					m_Width;
	float					m_Height;
	Position				m_Position;
	std::vector<std::vector<CSprite *>>	m_Sprites;
};
