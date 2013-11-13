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
}

// ----------------------------------------------------------------
//	LoadResource
// ----------------------------------------------------------------
bool CD2DBitmap::LoadResource( ResourceId id )
{
	ID2D1HwndRenderTarget * renderTarget = CD2DRenderer::GetInstance().GetHwndRenderTarget();
	IWICImagingFactory * imagingFactory = CD2DRenderer::GetInstance().GetImagingFactory();

	IWICBitmapDecoder * bitmapDecoder = nullptr;
	IWICBitmapFrameDecode* bitmapFrameDecode = nullptr;

	imagingFactory->CreateDecoderFromFilename( id.c_str(), nullptr, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &bitmapDecoder );
	bitmapDecoder->GetFrame( 0, &bitmapFrameDecode );

	imagingFactory->CreateFormatConverter( &m_FmtConverter );
	m_FmtConverter->Initialize( bitmapFrameDecode, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, nullptr, 0.0f, WICBitmapPaletteTypeCustom );

	renderTarget->CreateBitmapFromWicBitmap( m_FmtConverter, nullptr, &m_D2DBitmap );

	SafeRelease( bitmapDecoder );
	SafeRelease( bitmapFrameDecode );

	return true;
}


// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CD2DBitmap::Release()
{
	SafeRelease( m_D2DBitmap );
	SafeRelease( m_FmtConverter );
}