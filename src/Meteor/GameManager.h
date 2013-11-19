// @author	Lee JinWoo (2013.11.6)
#pragma once

#include "IGamemanager.h"
#include "Scene.h"
#include "Fps.h"
#include <chrono>

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

	void SetWidth( long width ) { m_Width = width; }
	void SetHeight( long height ) { m_Height = height; }
	long GetWidth() const { return m_Width; }
	long GetHeight() const { return m_Height; }

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
	std::chrono::system_clock::time_point	m_StartTime;
	std::chrono::system_clock::time_point	m_LastTime;

	// Window Size
	long	m_Width;
	long	m_Height;
};

