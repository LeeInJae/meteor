/**
 * @file	ResourceManager.cpp
 * @brief
 * @author	Lee JinWoo
 *
 */

#include "stdafx.h"
#include "Bitmap.h"
#include "IRenderer.h"
#include "MainWindow.h"
#include "D2DRenderer.h"

// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CBitmap::Release()
{
}

CBitmap* CBitmap::CreateResource( std::wstring path )
{
	static RendererStatus rendererStatus = CMainWindow::GetInstance()->GetRendererStatus();

	CBitmap* pInstance = nullptr;

	switch( rendererStatus )
	{
	case D2D:
		pInstance = new CD2DTexture( path );
		break;
	default:
		break;
	}
	return pInstance;
}

IWICImagingFactory* CD2DTexture::g_pWICFactory = nullptr;

CD2DTexture::CD2DTexture() : m_D2DBitmap(nullptr), m_FmtConverter(nullptr) 
{

}

CD2DTexture::CD2DTexture( std::wstring path )
{
	if( g_pWICFactory == nullptr )
	{
		CoCreateInstance( CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&g_pWICFactory) );
	}

	m_Path = path;
	IWICBitmapDecoder* bitmapDecoder = nullptr;
	g_pWICFactory->CreateDecoderFromFilename( path.c_str(), nullptr, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &bitmapDecoder );

	IWICBitmapFrameDecode* bitmapFrameDecode = nullptr;
	bitmapDecoder ->GetFrame(0, &bitmapFrameDecode);

	g_pWICFactory->CreateFormatConverter(&m_FmtConverter);

	m_FmtConverter->Initialize(bitmapFrameDecode, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, nullptr, 0.0f, WICBitmapPaletteTypeCustom);

	CD2DRenderer* pD2DRenderer = static_cast<CD2DRenderer*>(CMainWindow::GetInstance()->GetRenderer());

	pD2DRenderer->GetHwndRenderTarget()->CreateBitmapFromWicBitmap( m_FmtConverter, nullptr, &m_D2DBitmap );

	//SafeRelease( bitmapDecoder );
	//SafeRelease( bitmapFrameDecode );
}

CD2DTexture::~CD2DTexture()
{

	Destroy();
//	SafeRelease( g_pWICFactory );
}

void CD2DTexture::Destroy()
{

//	SafeRelease( m_D2DBitmap );
//	SafeRelease( m_FmtConverter );
}