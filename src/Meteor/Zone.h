
//@author : 이인재, 조익성 (2013. 11. 01)

#pragma once

#include "GameObject.h"
#include <string>

class CZone
{
public:
	CZone(void);
	CZone( std::string key );
	virtual ~CZone(void);
	std::list< CGameObject * > GetObject() { return m_Object; }
	bool LoadZone(); 
	//TODO: GetMapData() 

private:
	int m_Width, m_Height;
	std::list< CGameObject * > m_Object;
	std::string m_ZoneKey;
//TODO : 
	//Map Data관련 변수
};