// @author	Lee JinWoo (2013.11.6)
#pragma once

class IGameManager
{
public:
	virtual ~IGameManager() {};

	virtual bool Init() = 0;
	virtual bool Process() = 0;
	virtual void Release() = 0;
};
