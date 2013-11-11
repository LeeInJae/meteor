/**
 * @file	D2DRenderer.cpp
 * @brief
 * @author	Lee JinWoo
 *
 */

#include "stdafx.h"
#include "D2DRenderer.h"
#include "MainWindow.h"
#include <d2d1.h>

// ----------------------------------------------------------------
//	Init
// ----------------------------------------------------------------
bool CD2DRenderer::Init()
{
	HRESULT hr;
	hr = D2D1CreateFactory( D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_ipD2DFactory );
	if( hr != S_OK )
		return false;

	HWND hwnd = CMainWindow::GetInstance().Window();
	RECT rt;
	GetClientRect( hwnd, &rt );
	m_Width = rt.right - rt.left;
	m_Height = rt.bottom - rt.top;

	hr = m_ipD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties( hwnd, D2D1::SizeU( m_Width, m_Height ), D2D1_PRESENT_OPTIONS_IMMEDIATELY ),
		&m_ipRenderTarget );

	if( hr != S_OK )
		return false;

	return true;
}

// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
bool CD2DRenderer::Release()
{
	SafeRelease( m_ipD2DFactory );
	SafeRelease( m_ipRenderTarget );
	return true;
}

// ----------------------------------------------------------------
//	Begin
// ----------------------------------------------------------------
bool CD2DRenderer::Begin()
{
	m_ipRenderTarget->BeginDraw();
	return true;
}

// ----------------------------------------------------------------
//	End
// ----------------------------------------------------------------
bool CD2DRenderer::End()
{
	m_ipRenderTarget->EndDraw();
	return true;
}

// ----------------------------------------------------------------
//	Clear
// ----------------------------------------------------------------
bool CD2DRenderer::Clear()
{
	m_ipRenderTarget->Clear( D2D1::ColorF( D2D1::ColorF::White ));
	return true;
}

// ----------------------------------------------------------------
//	GetInstance
// ----------------------------------------------------------------
CD2DRenderer & CD2DRenderer::GetInstance()
{
	static CD2DRenderer instance;

	return instance;
}

// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CD2DRenderer::CD2DRenderer()
	: m_ipD2DFactory(nullptr)
	, m_ipRenderTarget(nullptr)
{
}

// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
CD2DRenderer::~CD2DRenderer()
{
	Release();
}
