#include "stdafx.h"
#include "GameManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "D2DRenderer.h"
#include "D2DText.h"

// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CGameManager::CGameManager(void)
	: m_Scene(nullptr)
	, m_StartTime(std::chrono::system_clock::now())
	, m_LastTime(std::chrono::system_clock::now())
	, m_Width(0)
	, m_Height(0)
{
}


// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
CGameManager::~CGameManager(void)
{
}


// ----------------------------------------------------------------
//	Init
// ----------------------------------------------------------------
bool CGameManager::Init()
{
	IRenderer & renderer = CD2DRenderer::GetInstance();

	renderer.Init();
	m_Width = renderer.GetWidth();
	m_Height = renderer.GetHeight();

	m_Scene = new CScene();
	m_LastTime = m_StartTime = std::chrono::system_clock::now();

	m_Fps = new CFps();

	return true;
}


// ----------------------------------------------------------------
//	Process
// ----------------------------------------------------------------
bool CGameManager::Process()
{
	if ( ! m_Scene )
		return true;

	std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
	float elapsedTime = static_cast< std::chrono::duration< float > >( currentTime - m_LastTime ).count();

	if ( elapsedTime > 1e-6f )
	{
		// --------------------------------
		//	Update
		// --------------------------------
		CInputManager::GetInstance().UpdateKeyState();

		m_Fps->Update( elapsedTime );
		m_Scene->Update( elapsedTime );

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
// ---------------------------------------------------------------
void CGameManager::Release()
{
	CResourceManager::GetInstance().Clear();
	CD2DRenderer::GetInstance().Release();
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

