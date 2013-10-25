/**
 * @file	D2DRenderer.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "IRenderer.h"

#include <d2d1.h>

class CD2DRenderer : public IRenderer
{
public:
	// --------------------------------
	//	IRenderer interface
	// --------------------------------
	bool Init();
	bool Release();

	bool Begin();
	bool End();
	bool Clear();

	// --------------------------------
	//	GetInstance
	// --------------------------------
	static CD2DRenderer & GetInstance();

	ID2D1Factory * GetD2DFactory() const				{ return m_ipD2DFactory; }
	ID2D1HwndRenderTarget * GetHwndRenderTarget() const	{ return m_ipRenderTarget; }

private:
	CD2DRenderer();
	~CD2DRenderer();
	CD2DRenderer( const CD2DRenderer & );
	CD2DRenderer & operator=( const CD2DRenderer & );

	ID2D1Factory *			m_ipD2DFactory;
	ID2D1HwndRenderTarget *	m_ipRenderTarget;
};
