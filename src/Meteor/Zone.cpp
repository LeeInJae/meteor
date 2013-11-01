#include "stdafx.h"
#include "Zone.h"


CZone::CZone(void)
{

}

CZone::CZone( std::string key )
	: m_ZoneKey( key )
{

}

CZone::~CZone(void)
{
}

bool CZone::LoadZone()
{
	return false;
}