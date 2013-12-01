// @author	Lee JinWoo (2013.10.23)
#pragma once

enum SceneId
{
	ID_SCENE_INTRO,
	ID_SCENE_LOADING,
	ID_SCENE_PLAY,

	ID_SCENE_MAX
};

class ISceneManager
{
public:
	virtual ~ISceneManager() {};

	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void ChangeScene( SceneId sceneId ) = 0;
	virtual bool UpdateScene( float deltaTime ) = 0;
	virtual void RenderScene() = 0;
};
