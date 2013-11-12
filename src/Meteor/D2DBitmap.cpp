/**
 * @file	ResourceManager.cpp
 * @brief
 * @author	Lee JinWoo
 *
 */

#include "stdafx.h"
#include "D2DBitmap.h"
#include "MainWindow.h"
#include "D2DRenderer.h"

// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------

CD2DBitmap::CD2DBitmap()
	: m_D2DBitmap(nullptr)
	, m_FmtConverter(nullptr) 
{
}

// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
CD2DBitmap::~CD2DBitmap()
{
	Release();
	
	// agebreak : static 변수로 만들었는데, 소멸자에서 Release를 해줘버리면??
	SafeRelease( g_pWICFactory );
}

// ----------------------------------------------------------------
//	LoadResource
// ----------------------------------------------------------------
bool CD2DBitmap::LoadResource( std::wstring path )
{
	if ( g_pWICFactory == nullptr)
	{
		HRESULT ret = CoCreateInstance( CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&g_pWICFactory) );
		if( ret == REGDB_E_CLASSNOTREG ) 
		{
			CoCreateInstance( CLSID_WICImagingFactory1, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&g_pWICFactory) );
		}
	}

	m_Path = path;
	IWICBitmapDecoder * bitmapDecoder = nullptr;
	g_pWICFactory->CreateDecoderFromFilename( path.c_str(), nullptr, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &bitmapDecoder );

	IWICBitmapFrameDecode* bitmapFrameDecode = nullptr;
	bitmapDecoder->GetFrame( 0, &bitmapFrameDecode );

	g_pWICFactory->CreateFormatConverter( &m_FmtConverter );

	m_FmtConverter->Initialize( bitmapFrameDecode, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, nullptr, 0.0f, WICBitmapPaletteTypeCustom );

	CD2DRenderer::GetInstance().GetHwndRenderTarget()->CreateBitmapFromWicBitmap( m_FmtConverter, nullptr, &m_D2DBitmap );

	SafeRelease( bitmapDecoder );
	SafeRelease( bitmapFrameDecode );

	return true;
}

// ----------------------------------------------------------------
//	g_pWICFactory
// ----------------------------------------------------------------
IWICImagingFactory * CD2DBitmap::g_pWICFactory = nullptr;


// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CD2DBitmap::Release()
{
	SafeRelease( m_D2DBitmap );
	SafeRelease( m_FmtConverter );
}