// @author	Lee JinWoo (2013.10.23)
#pragma once

class ISceneManager
{
public:
	virtual ~ISceneManager() {};

	virtual bool Init() = 0;
	virtual bool Release() = 0;
	virtual bool UpdateScene() = 0;
	virtual bool RenderScene() = 0;
};
