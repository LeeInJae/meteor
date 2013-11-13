#include "stdafx.h"
#include "SpriteInfo.h"
#include "Sprite.h"
#include "ResourceManager.h"

CSpriteInfo::CSpriteInfo()
	: m_BitmapId( L"" )
	, m_Left( 0.0f )
	, m_Top( 0.0f )
	, m_Width( 1.0f )
	, m_Height( 1.0f )
	, m_SpriteWidth( 64.0f )
	, m_SpriteHeight( 128.0f )
	, m_OriginX( 0.0f )
	, m_OriginY( 0.0f )
{
}


CSpriteInfo::~CSpriteInfo(void)
{
}


// ----------------------------------------------------------------
//	LoadResource
// ----------------------------------------------------------------
bool CSpriteInfo::LoadResource( ResourceId id )
{
	// TODO: Temporary Code
	if( id == L"character_walk_left_01" )
	{
		m_BitmapId = L"CHARACTER_WALK_RIGHT_01.png";
		m_Width = -1.0f;
		m_OriginX = -4.0f;
		m_SpriteWidth = 50.0f;
		m_SpriteHeight = 100.0f;
	}
	if( id == L"character_walk_left_02" )
	{
		m_BitmapId = L"CHARACTER_WALK_RIGHT_02.png";
		m_Width = -1.0f;
		m_SpriteWidth = 60.0f;
		m_SpriteHeight = 98.0f;
	}
	if( id == L"character_walk_left_03" )
	{
		m_BitmapId = L"CHARACTER_WALK_RIGHT_03.png";
		m_Width = -1.0f;
		m_SpriteWidth = 60.0f;
		m_SpriteHeight = 98.0f;
	}

	if( id == L"character_walk_right_01" )
	{
		m_BitmapId = L"CHARACTER_WALK_RIGHT_01.png";
		m_OriginX = 4.0f;
		m_SpriteWidth = 50.0f;
		m_SpriteHeight = 100.0f;
	}
	if( id == L"character_walk_right_02" )
	{
		m_BitmapId = L"CHARACTER_WALK_RIGHT_02.png";
		m_SpriteWidth = 60.0f;
		m_SpriteHeight = 98.0f;
	}
	if( id == L"character_walk_right_03" )
	{
		m_BitmapId = L"CHARACTER_WALK_RIGHT_03.png";
		m_SpriteWidth = 60.0f;
		m_SpriteHeight = 98.0f;
	}

	if( id == L"character_walk_up_01" )
	{
		m_BitmapId = L"CHARACTER_WALK_UP_01.png";
		m_OriginX = 2.0f;
		m_SpriteWidth = 56.0f;
		m_SpriteHeight = 100.0f;
	}
	if( id == L"character_walk_up_02" )
	{
		m_BitmapId = L"CHARACTER_WALK_UP_02.png";
		m_SpriteWidth = 48.0f;
		m_SpriteHeight = 102.0f;
	}
	if( id == L"character_walk_up_03" )
	{
		m_BitmapId = L"CHARACTER_WALK_UP_03.png";
		m_SpriteWidth = 48.0f;
		m_SpriteHeight = 102.0f;
	}

	if( id == L"character_walk_down_01" )
	{
		m_BitmapId = L"CHARACTER_WALK_DOWN_01.png";
		m_SpriteWidth = 56.0f;
		m_SpriteHeight = 100.0f;
	}
	if( id == L"character_walk_down_02" )
	{
		m_BitmapId = L"CHARACTER_WALK_DOWN_02.png";
		m_SpriteWidth = 56.0f;
		m_SpriteHeight = 104.0f;
	}
	if( id == L"character_walk_down_03" )
	{
		m_BitmapId = L"CHARACTER_WALK_DOWN_03.png";
		m_SpriteWidth = 56.0f;
		m_SpriteHeight = 104.0f;
	}

	return false;
}


// ----------------------------------------------------------------
//	CreateSprite
// ----------------------------------------------------------------
CSprite * CSpriteInfo::CreateSprite()
{
	CD2DSprite * sprite = new CD2DSprite();
	CD2DBitmap * bitmap = static_cast<CD2DBitmap *>( CResourceManager::GetInstance().GetResource( m_BitmapId ) );

	sprite->SetBaseMatrix( D2D1::Matrix3x2F::Scale( m_Width, m_Height, D2D1::Point2F( m_SpriteWidth * 0.5f, m_SpriteHeight * 0.5f ) ) * D2D1::Matrix3x2F::Translation( -m_OriginX, -m_OriginY ) );
	sprite->SetImageWidth( m_SpriteWidth );
	sprite->SetImageHeight( m_SpriteHeight );
	sprite->SetBitmap( bitmap );

	return sprite;
}


// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CSpriteInfo::Release()
{
	CResourceManager::GetInstance().ReleaseResource(this);
}


// ----------------------------------------------------------------
//	SetBitmap
// ----------------------------------------------------------------
void CSpriteInfo::SetBitmap( ResourceId bitmapId )
{
	m_BitmapId = bitmapId;
}


// ----------------------------------------------------------------
//	SetPosition
// ----------------------------------------------------------------
void CSpriteInfo::SetPosition( float left, float top, float width, float height )
{
	m_Left		= left;
	m_Top		= top;
	m_Width		= width;
	m_Height	= height;
}
