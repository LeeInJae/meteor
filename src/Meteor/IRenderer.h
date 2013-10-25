/**
 * @file	IRenderer.h
 * @brief
 * @author	Lee JinWoo
 *
 */

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
};