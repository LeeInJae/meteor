#pragma once

class IRender
{
public:
	virtual ~IRender() {}

	virtual bool Init() = 0;
	virtual bool Release() = 0;

	virtual bool Begin() = 0;
	virtual bool End() = 0;
	virtual bool Clear() = 0;
};