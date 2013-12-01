//author	Lee InJae(2013. 10. 30)

#pragma once
#include "ISceneManager.h"
#include "Scene.h"

class CSceneManager : public ISceneManager
{
public:
	~CSceneManager(void);

	CScene *	GetCurrentScene()			{ return m_Scene; }

	// --------------------------------
	//	ISceneManager interface
	// --------------------------------
	void		Init();
	void		Release();
	void		ChangeScene( SceneId sceneId );
	bool		UpdateScene( float deltaTime );
	void		RenderScene();

	// --------------------------------
	//	GetInstance
	// --------------------------------
	static CSceneManager & GetInstance();

private:
	CSceneManager();
	CSceneManager( const CSceneManager & );
	CSceneManager & operator=( const CSceneManager & );

	CScene *	m_Scene;
};