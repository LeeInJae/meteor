#pragma once

#include "IResource.h"

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

private:
	bool LoadMap();
	bool LoadObjects();

	std::wstring m_ZoneId;

	//  Zone Header ( 40 byte )
	ZoneHeader m_Header;

	//  Object list ( 60 byte )
	std::list< ObjectData > m_Objects;
};

