#include "stdafx.h"
#include "GameManager.h"
#include "InputManager.h"
#include "D2DRenderer.h"
#include "D2DText.h"
#include <Mmsystem.h>

// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CGameManager::CGameManager(void)
	: m_Scene(nullptr)
	, m_StartTime(0)
	, m_LastTime(0)
{
}


// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
CGameManager::~CGameManager(void)
{
	Release();
}


// ----------------------------------------------------------------
//	Init
// ----------------------------------------------------------------
bool CGameManager::Init()
{
	CD2DRenderer::GetInstance().Init();

	m_Scene = new CScene();
	m_LastTime = m_StartTime = timeGetTime();

	m_Fps = new CFps();

	return true;
}


// ----------------------------------------------------------------
//	Process
// ----------------------------------------------------------------
bool CGameManager::Process()
{
	if ( ! m_Scene )
		return false;

	DWORD currentTime = timeGetTime();
	DWORD elapsedTime = currentTime - m_LastTime;

	//if ( elapsedTime > ( 1000 / 60 ) )
	{
		// --------------------------------
		//	Update
		// --------------------------------
		CInputManager::GetInstance().UpdateKeyState();

		m_Fps->Update( elapsedTime );
		m_Scene->Update( static_cast<float>(currentTime - m_LastTime) );

		m_LastTime = currentTime;

		// --------------------------------
		//	Render
		// --------------------------------
		CD2DRenderer::GetInstance().Begin();
		CD2DRenderer::GetInstance().Clear();

		m_Scene->Render();
		m_Fps->Render();

		CD2DRenderer::GetInstance().End();
	}

	return true;
}


// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CGameManager::Release()
{
	SafeDelete( m_Scene );
	SafeDelete( m_Fps );
}


// ----------------------------------------------------------------
//	GetInstance
// ----------------------------------------------------------------
CGameManager & CGameManager::GetInstance()
{
	static CGameManager instance;
	return instance;
}

