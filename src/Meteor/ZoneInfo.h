#pragma once

#include "IResource.h"
#include "ZoneMap.h"

#include <string>

struct ZoneHeader
{
	char mapType[32];
	UINT mapNo;
	UINT numOfObject;
};

struct ObjectData
{
	char objectType[16];
	char objectId[32];
	USHORT objectX;
	USHORT objectY;
	USHORT objectDirection;
	USHORT Reserved;
};

// ----------------------------------------------------------------
//	CZoneInfo
// ----------------------------------------------------------------
class CZoneInfo : public IResource
{
public:
	CZoneInfo( std::wstring zoneId );
	~CZoneInfo(void);

	bool LoadResource();
	void Release();

	ZoneHeader * GetHeader() { return &m_Header; }
	std::list< ObjectData > * GetObjects() { return &m_Objects; }

private:
	bool LoadMap();
	bool LoadObjects();

	std::wstring			m_ZoneId;

	ZoneHeader				m_Header;	//	Zone Header	( 40 byte )
	std::list< ObjectData >	m_Objects;	//	Object list	( 56 byte )
};

