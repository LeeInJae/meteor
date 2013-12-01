#pragma once

#include "IResource.h"
#include "Position.h"
#include "D2DRenderer.h"
#include "D2DBitmap.h"

#include <string>

class CSprite
{
public:
	CSprite()
		: m_ImageWidth(0.f), m_ImageHeight(0.f),
		m_ColorR(0.f), m_ColorG(0.f), m_ColorB(0.f), m_Opacity(1.f)
	{}
	virtual ~CSprite(){}
	virtual void Release() {}
	virtual void Render() {}

	float GetImageWidth()	const { return m_ImageWidth; }
	float GetImageHeight()	const { return m_ImageHeight; }

	void SetPosition	( Position position )	{ m_Position = position; }
	void SetImageWidth	( float width )			{ m_ImageWidth = width; }
	void SetImageHeight	( float height )		{ m_ImageHeight = height; }
	void SetOpacity		( float opacity	)		{ m_Opacity = opacity; }

protected:
	Position m_Position;

	float m_ImageWidth;
	float m_ImageHeight;
	float m_ColorR, m_ColorG, m_ColorB;
	float m_Opacity;
};

class CD2DSprite : public CSprite
{
public:
	CD2DSprite();
	~CD2DSprite();

	void Render();

	void SetBaseMatrix( D2D1::Matrix3x2F baseMatrix ) { m_BaseMatrix = baseMatrix; }
	void SetBitmap( CD2DBitmap * bitmap ) { m_pD2DBitmap = bitmap; }

private:
	CD2DBitmap *		m_pD2DBitmap;
	D2D1::Matrix3x2F	m_BaseMatrix;
};