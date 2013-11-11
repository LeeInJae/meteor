// @author	Lee JinWoo (2013.10.20)
#pragma once

class IRenderer
{
public:
	virtual ~IRenderer() {}

	virtual bool Init() = 0;
	virtual bool Release() = 0;

	virtual bool Begin() = 0;
	virtual bool End() = 0;
	virtual bool Clear() = 0;

	virtual long GetWidth() const = 0;
	virtual long GetHeight() const = 0;
};