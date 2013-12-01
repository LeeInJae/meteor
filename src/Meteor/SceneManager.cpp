#include "stdafx.h"
#include "SceneManager.h"
#include "Scene.h"
#include "UIManager.h"

// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CSceneManager::CSceneManager(void)
	: m_Scene(nullptr)
{
}


// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
CSceneManager::~CSceneManager(void)
{
}


// ----------------------------------------------------------------
//	Init
// ----------------------------------------------------------------
void CSceneManager::Init()
{
	m_Scene = new CScene();
	CUIManager::GetInstance().Init();
}


// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CSceneManager::Release()
{
	CUIManager::GetInstance().Release();
	SafeDelete( m_Scene );
}


// ----------------------------------------------------------------
//	ChangeScene
// ----------------------------------------------------------------
void CSceneManager::ChangeScene( SceneId sceneId )
{
	// if ( currentSceneId != sceneId )
	//	GetScene
	CUIManager::GetInstance().CloseAll();
}


// ----------------------------------------------------------------
//	UpdateScene
// ----------------------------------------------------------------
bool CSceneManager::UpdateScene( float deltaTime )
{
	CUIManager::GetInstance().UpdateUI( deltaTime );

	if ( m_Scene )
		return m_Scene->Update( deltaTime );
	return false;
}


// ----------------------------------------------------------------
//	RenderScene
// ----------------------------------------------------------------
void CSceneManager::RenderScene()
{
	if ( m_Scene )
		m_Scene->Render();

	CUIManager::GetInstance().RenderUI();
}


// ----------------------------------------------------------------
//	GetInstance
// ----------------------------------------------------------------
CSceneManager & CSceneManager::GetInstance()
{
	static CSceneManager instance;
	return instance;
}
