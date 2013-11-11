#pragma once

#include "IResource.h"

class CSprite;

class CSpriteInfo : public IResource
{
public:
	CSpriteInfo();
	~CSpriteInfo();

	bool LoadResource( ResourceId id );
	CSprite * CreateSprite();

	// --------------------------------
	//	IResource interface
	// --------------------------------
	void Release();

private:
	friend class CResourceManager;
	void SetBitmap( ResourceId bitmapId );
	void SetPosition( float left, float top, float width, float height );

	ResourceId	m_BitmapId;
	float		m_Left;
	float		m_Top;
	float		m_Width;
	float		m_Height;
	float		m_SpriteWidth;
	float		m_SpriteHeight;
	float		m_OriginX;
	float		m_OriginY;
};
