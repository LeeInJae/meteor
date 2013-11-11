#include "stdafx.h"
#include "Sprite.h"
#include "MainWindow.h"
#include "D2DBitmap.h"
#include "ResourceManager.h"

CD2DSprite::CD2DSprite()
	: m_pD2DBitmap(nullptr)
{
}


void CD2DSprite::Render()
{
	float left;
	float top;

	switch ( m_Position.mode )
	{
	case BASE_CENTER:
		left = m_Position.x - m_ImageWidth / 2;
		top = m_Position.y - m_ImageHeight / 2;
		break;
	case BASE_TOPLEFT:
		left = m_Position.x;
		top = m_Position.y;
		break;
	default:
		break;
	}

	D2D1::Matrix3x2F matrix = D2D1::Matrix3x2F::Translation( left, top );
	CD2DRenderer::GetInstance().GetHwndRenderTarget()->SetTransform( matrix * m_BaseMatrix );
	CD2DRenderer::GetInstance().GetHwndRenderTarget()->DrawBitmap(m_pD2DBitmap->GetD2DBitmap(), D2D1::RectF(0.f, 0.f, m_ImageWidth, m_ImageHeight), m_Opacity );
}


void CD2DSprite::Release()
{
	SafeRelease( m_pD2DBitmap );
	CResourceManager::GetInstance().ReleaseResource( this );
}


CD2DSprite::~CD2DSprite()
{
	Release();
}