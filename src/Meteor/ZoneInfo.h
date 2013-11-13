#pragma once

#include "IResource.h"
#include "ZoneMap.h"
#include <string>

class CZone;

struct ZoneHeader
{
	wchar_t mapType[32];
	UINT mapNo;
	UINT numOfObject;
};

struct ObjectData
{
	wchar_t objectType[16];
	wchar_t objectId[32];
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
	CZoneInfo();
	~CZoneInfo(void);

	bool LoadResource( std::wstring zoneId );
	CZone * CreateZone();
	//ZoneHeader * GetHeader() { return &m_Header; }
	//std::list< ObjectData * > * GetObjects() { return &m_Objects; }

	// --------------------------------
	//	IResource interface
	// --------------------------------
	void Release();

private:
	bool LoadMap();
	bool LoadObjects();

	ZoneHeader				m_Header;	//	Zone Header	( 40 byte )
	std::list< ObjectData >	m_Objects;	//	Object list	( 56 byte )
};

