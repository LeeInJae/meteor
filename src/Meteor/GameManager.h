// @author	Lee JinWoo (2013.11.6)
#pragma once

#include "IGamemanager.h"
#include "Scene.h"
#include "Fps.h"

class CGameManager : public IGameManager
{
public:
	~CGameManager(void);

	// --------------------------------
	//	IGamemanager interface
	// --------------------------------
	bool Init();
	bool Process();
	void Release();

	// --------------------------------
	//	GetInstance
	// --------------------------------
	static CGameManager & GetInstance();

private:
	CGameManager();
	CGameManager( const CGameManager & );
	CGameManager & operator=( const CGameManager & );

	CScene *	m_Scene;
	CFps *		m_Fps;

	// Time and Fps
	DWORD	m_StartTime;
	DWORD	m_LastTime;
};

