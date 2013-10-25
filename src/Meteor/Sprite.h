#pragma once
#include "GameObject.h"
#include <string>
#include "D2DRenderer.h"
#include "Bitmap.h"

class CSprite : public CGameObject
{
protected:
	float m_ImageWidth;
	float m_ImageHeight;
	float m_ColorR, m_ColorG, m_ColorB;
	float m_Opacity;

public:
	CSprite()
		: m_ImageWidth(0.f), m_ImageHeight(0.f),
		m_ColorR(0.f), m_ColorG(0.f), m_ColorB(0.f), m_Opacity(1.f)
	{}
	virtual ~CSprite(){}
	static CSprite* Create( std::wstring path );
	virtual void Destroy() {}
	virtual void Render() {}

	float GetImageWidth()	const { return m_ImageWidth; }
	float GetImageHeight()	const { return m_ImageHeight; }
	float GetOpacity()		const { return m_Opacity; }
	
	void SetImageWidth	( float width )		{ m_ImageWidth = width; }
	void SetImageHeight	( float height )	{ m_ImageHeight = height; }
	void SetOpacity		( float opacity )	{ m_Opacity = opacity; }
};

class CD2DSprite : public CSprite
{
public:
	CD2DSprite();
	CD2DSprite( std::wstring path );

	void Destroy();
	void Render();

private:
	CD2DRenderer*	m_pD2DRenderer;
	CD2DTexture*	m_pD2DTExture;
};