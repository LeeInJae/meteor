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
	assert( m_D2DFactory == nullptr );
	assert( m_RenderTarget == nullptr );
	assert( m_ImagingFactory == nullptr );

	HRESULT hr;
	hr = D2D1CreateFactory( D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_D2DFactory );
	if( hr != S_OK )
	{
		Release();
		return false;
	}

	HWND hwnd = CMainWindow::GetInstance().Window();
	RECT rt;
	GetClientRect( hwnd, &rt );
	m_Width = rt.right - rt.left;
	m_Height = rt.bottom - rt.top;

	hr = m_D2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties( hwnd, D2D1::SizeU( m_Width, m_Height ), D2D1_PRESENT_OPTIONS_IMMEDIATELY ),
		&m_RenderTarget );

	if( hr != S_OK )
	{
		Release();
		return false;
	}

	hr = CoCreateInstance( CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_ImagingFactory) );
	if( hr == REGDB_E_CLASSNOTREG ) 
		hr = CoCreateInstance( CLSID_WICImagingFactory1, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_ImagingFactory) );
	if( hr != S_OK )
	{
		Release();
		return false;
	}

	return true;
}

// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
bool CD2DRenderer::Release()
{
	SafeRelease( m_D2DFactory );
	SafeRelease( m_RenderTarget );
	SafeRelease( m_ImagingFactory );
	return true;
}

// ----------------------------------------------------------------
//	Begin
// ----------------------------------------------------------------
bool CD2DRenderer::Begin()
{
	m_RenderTarget->BeginDraw();
	return true;
}

// ----------------------------------------------------------------
//	End
// ----------------------------------------------------------------
bool CD2DRenderer::End()
{
	m_RenderTarget->EndDraw();
	return true;
}

// ----------------------------------------------------------------
//	Clear
// ----------------------------------------------------------------
bool CD2DRenderer::Clear()
{
	m_RenderTarget->Clear( D2D1::ColorF( D2D1::ColorF::White ));
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
	: m_D2DFactory(nullptr)
	, m_RenderTarget(nullptr)
	, m_ImagingFactory(nullptr)
{
}

// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
CD2DRenderer::~CD2DRenderer()
{
	Release();
}
