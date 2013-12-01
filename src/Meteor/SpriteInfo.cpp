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
	
	if( id.find(L"character") != std::wstring::npos )
	{
		if( id == L"character_walk_left_01" )
		{
			m_Width = -1.0f;
			m_OriginX = -4.0f;
			m_SpriteWidth = 50.0f;
			m_SpriteHeight = 100.0f;
		}
		else if( id == L"character_walk_left_02" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 60.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_walk_left_03" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 60.0f;
			m_SpriteHeight = 98.0f;
		}

		else if( id == L"character_walk_right_01" )
		{
			m_OriginX = 4.0f;
			m_SpriteWidth = 50.0f;
			m_SpriteHeight = 100.0f;
		}
		else if( id == L"character_walk_right_02" )
		{
			m_SpriteWidth = 60.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_walk_right_03" )
		{
			m_SpriteWidth = 60.0f;
			m_SpriteHeight = 98.0f;
		}

		else if( id == L"character_walk_up_01" )
		{
			m_OriginX = 2.0f;
			m_SpriteWidth = 56.0f;
			m_SpriteHeight = 100.0f;
		}
		else if( id == L"character_walk_up_02" )
		{
			m_SpriteWidth = 48.0f;
			m_SpriteHeight = 102.0f;
		}
		else if( id == L"character_walk_up_03" )
		{
			m_SpriteWidth = 48.0f;
			m_SpriteHeight = 102.0f;
		}

		else if( id == L"character_walk_up_left_01" )
		{
			m_OriginX = 2.0f;
			m_Width = -1.0f;
			m_SpriteWidth = 48.0f;
			m_SpriteHeight = 100.0f;
		}
		else if( id == L"character_walk_up_left_02" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 52.0f;
			m_SpriteHeight = 102.0f;
		}
		else if( id == L"character_walk_up_left_03" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 52.0f;
			m_SpriteHeight = 102.0f;
		}

		else if( id == L"character_walk_up_right_01" )
		{
			m_OriginX = 2.0f;
			m_SpriteWidth = 48.0f;
			m_SpriteHeight = 100.0f;
		}
		else if( id == L"character_walk_up_right_02" )
		{
			m_SpriteWidth = 52.0f;
			m_SpriteHeight = 102.0f;
		}
		else if( id == L"character_walk_up_right_03" )
		{
			m_SpriteWidth = 52.0f;
			m_SpriteHeight = 102.0f;
		}

		else if( id == L"character_walk_down_01" )
		{
			m_SpriteWidth = 56.0f;
			m_SpriteHeight = 100.0f;
		}
		else if( id == L"character_walk_down_02" )
		{
			m_SpriteWidth = 56.0f;
			m_SpriteHeight = 104.0f;
		}
		else if( id == L"character_walk_down_03" )
		{
			m_SpriteWidth = 56.0f;
			m_SpriteHeight = 104.0f;
		}

		else if( id == L"character_walk_down_left_01" )
		{
			m_SpriteWidth = 50.0f;
			m_SpriteHeight = 100.0f;
		}
		else if( id == L"character_walk_down_left_02" )
		{
			m_SpriteWidth = 58.0f;
			m_SpriteHeight = 100.0f;
		}
		else if( id == L"character_walk_down_left_03" )
		{
			m_SpriteWidth = 58.0f;
			m_SpriteHeight = 100.0f;
		}

		else if( id == L"character_walk_down_right_01" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 50.0f;
			m_SpriteHeight = 100.0f;
		}
		else if( id == L"character_walk_down_right_02" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 58.0f;
			m_SpriteHeight = 100.0f;
		}
		else if( id == L"character_walk_down_right_03" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 58.0f;
			m_SpriteHeight = 100.0f;
		}

		else if( id == L"character_slash_left_01" )
		{
			m_OriginX = -4.0f;
			m_SpriteWidth = 70.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_left_02" )
		{
			m_SpriteWidth = 70.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_left_03" )
		{
			m_SpriteWidth = 70.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_left_04" )
		{
			m_SpriteWidth = 70.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_left_05" )
		{
			m_SpriteWidth = 70.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_left_06" )
		{
			m_SpriteWidth = 70.0f;
			m_SpriteHeight = 106.0f;
		}

		else if( id == L"character_slash_right_01" )
		{
			m_Width = -1.0f;
			m_OriginX = 4.0f;
			m_SpriteWidth = 70.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_right_02" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 70.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_right_03" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 70.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_right_04" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 70.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_right_05" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 70.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_right_06" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 70.0f;
			m_SpriteHeight = 106.0f;
		}

		else if( id == L"character_slash_up_01" )
		{
			m_OriginX = 2.0f;
			m_SpriteWidth = 80.0f;
			m_SpriteHeight = 104.0f;
		}
		else if( id == L"character_slash_up_02" )
		{
			m_SpriteWidth = 80.0f;
			m_SpriteHeight = 104.0f;
		}
		else if( id == L"character_slash_up_03" )
		{
			m_SpriteWidth = 80.0f;
			m_SpriteHeight = 104.0f;
		}
		else if( id == L"character_slash_up_04" )
		{
			m_OriginX = 2.0f;
			m_SpriteWidth = 80.0f;
			m_SpriteHeight = 104.0f;
		}
		else if( id == L"character_slash_up_05" )
		{
			m_SpriteWidth = 80.0f;
			m_SpriteHeight = 104.0f;
		}
		else if( id == L"character_slash_up_06" )
		{
			m_SpriteWidth = 80.0f;
			m_SpriteHeight = 104.0f;
		}

		else if( id == L"character_slash_up_left_01" )
		{
			m_OriginX = 2.0f;
			m_SpriteWidth = 88.0f;
			m_SpriteHeight = 108.0f;
		}
		else if( id == L"character_slash_up_left_02" )
		{
			m_SpriteWidth = 88.0f;
			m_SpriteHeight = 108.0f;
		}
		else if( id == L"character_slash_up_left_03" )
		{
			m_SpriteWidth = 88.0f;
			m_SpriteHeight = 108.0f;
		}
		else if( id == L"character_slash_up_left_04" )
		{
			m_SpriteWidth = 88.0f;
			m_SpriteHeight = 108.0f;
		}
		else if( id == L"character_slash_up_left_05" )
		{
			m_SpriteWidth = 88.0f;
			m_SpriteHeight = 108.0f;
		}
		else if( id == L"character_slash_up_left_06" )
		{
			m_SpriteWidth = 88.0f;
			m_SpriteHeight = 108.0f;
		}

		else if( id == L"character_slash_up_right_01" )
		{
			m_OriginX = 2.0f;
			m_SpriteWidth = 80.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_up_right_02" )
		{
			m_SpriteWidth = 80.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_up_right_03" )
		{
			m_SpriteWidth = 80.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_up_right_04" )
		{
			m_SpriteWidth = 80.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_up_right_05" )
		{
			m_SpriteWidth = 80.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_up_right_06" )
		{
			m_SpriteWidth = 80.0f;
			m_SpriteHeight = 98.0f;
		}

		else if( id == L"character_slash_down_01" )
		{
			m_SpriteWidth = 86.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_down_02" )
		{
			m_SpriteWidth = 86.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_down_03" )
		{
			m_SpriteWidth = 86.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_down_04" )
		{
			m_SpriteWidth = 86.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_down_05" )
		{
			m_SpriteWidth = 86.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_down_06" )
		{
			m_SpriteWidth = 86.0f;
			m_SpriteHeight = 98.0f;
		}

		else if( id == L"character_slash_down_left_01" )
		{
			m_SpriteWidth = 76.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_down_left_02" )
		{
			m_SpriteWidth = 76.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_down_left_03" )
		{
			m_SpriteWidth = 76.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_down_left_04" )
		{
			m_SpriteWidth = 76.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_down_left_05" )
		{
			m_SpriteWidth = 76.0f;
			m_SpriteHeight = 98.0f;
		}
		else if( id == L"character_slash_down_left_06" )
		{
			m_SpriteWidth = 76.0f;
			m_SpriteHeight = 98.0f;
		}

		else if( id == L"character_slash_down_right_01" )
		{
			m_SpriteWidth = 84.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_down_right_02" )
		{
			m_SpriteWidth = 84.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_down_right_03" )
		{
			m_SpriteWidth = 84.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_down_right_04" )
		{
			m_SpriteWidth = 84.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_down_right_05" )
		{
			m_SpriteWidth = 84.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"character_slash_down_right_06" )
		{
			m_SpriteWidth = 84.0f;
			m_SpriteHeight = 106.0f;
		}

		m_BitmapId = L".\\Player\\" + id + L".png";
	}
	else if( id.find(L"skeleton_mage") != std::wstring::npos )
	{
		if( id == L"skeleton_mage_walk_left_01" )
		{
			m_OriginX = 4.0f;
			m_SpriteWidth = 56.0f;
			m_SpriteHeight = 104.0f;
		}
		else if( id == L"skeleton_mage_walk_left_02" )
		{
			m_SpriteWidth = 56.0f;
			m_SpriteHeight = 104.0f;
		}
		else if( id == L"skeleton_mage_walk_left_03" )
		{
			m_SpriteWidth = 56.0f;
			m_SpriteHeight = 104.0f;
		}

		else if( id == L"skeleton_mage_walk_right_01" )
		{
			m_Width = -1.0f;
			m_OriginX = -4.0f;
			m_SpriteWidth = 56.0f;
			m_SpriteHeight = 104.0f;
		}
		else if( id == L"skeleton_mage_walk_right_02" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 56.0f;
			m_SpriteHeight = 104.0f;
		}
		else if( id == L"skeleton_mage_walk_right_03" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 56.0f;
			m_SpriteHeight = 104.0f;
		}

		else if( id == L"skeleton_mage_walk_up_01" )
		{
			m_OriginX = 2.0f;
			m_SpriteWidth = 64.0f;
			m_SpriteHeight = 108.0f;
		}
		else if( id == L"skeleton_mage_walk_up_02" )
		{
			m_SpriteWidth = 64.0f;
			m_SpriteHeight = 108.0f;
		}
		else if( id == L"skeleton_mage_walk_up_03" )
		{
			m_SpriteWidth = 64.0f;
			m_SpriteHeight = 108.0f;
		}

		else if( id == L"skeleton_mage_walk_up_right_01" )
		{
			m_OriginX = 2.0f;
			m_SpriteWidth = 66.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"skeleton_mage_walk_up_right_02" )
		{
			m_SpriteWidth = 66.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"skeleton_mage_walk_up_right_03" )
		{
			m_SpriteWidth = 66.0f;
			m_SpriteHeight = 106.0f;
		}

		else if( id == L"skeleton_mage_walk_up_left_01" )
		{
			m_OriginX = 2.0f;
			m_Width = -1.0f;
			m_SpriteWidth = 66.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"skeleton_mage_walk_up_left_02" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 66.0f;
			m_SpriteHeight = 106.0f;
		}
		else if( id == L"skeleton_mage_walk_up_left_03" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 66.0f;
			m_SpriteHeight = 106.0f;
		}

		else if( id == L"skeleton_mage_walk_down_01" )
		{
			m_SpriteWidth = 78.0f;
			m_SpriteHeight = 110.0f;
		}
		else if( id == L"skeleton_mage_walk_down_02" )
		{
			m_SpriteWidth = 78.0f;
			m_SpriteHeight = 110.0f;
		}
		else if( id == L"skeleton_mage_walk_down_03" )
		{
			m_SpriteWidth = 78.0f;
			m_SpriteHeight = 110.0f;
		}

		else if( id == L"skeleton_mage_walk_down_left_01" )
		{
			m_SpriteWidth = 62.0f;
			m_SpriteHeight = 110.0f;
		}
		else if( id == L"skeleton_mage_walk_down_left_02" )
		{
			m_SpriteWidth = 62.0f;
			m_SpriteHeight = 110.0f;
		}
		else if( id == L"skeleton_mage_walk_down_left_03" )
		{
			m_SpriteWidth = 62.0f;
			m_SpriteHeight = 110.0f;
		}

		else if( id == L"skeleton_mage_walk_down_right_01" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 62.0f;
			m_SpriteHeight = 110.0f;
		}
		else if( id == L"skeleton_mage_walk_down_right_02" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 62.0f;
			m_SpriteHeight = 110.0f;
		}
		else if( id == L"skeleton_mage_walk_down_right_03" )
		{
			m_Width = -1.0f;
			m_SpriteWidth = 62.0f;
			m_SpriteHeight = 110.0f;
		}

		m_BitmapId = L".\\Monster\\" + id + L".png";
	}
	else if( id.find(L"cast_") != std::wstring::npos )
	{
			m_SpriteWidth = 16.0f;
			m_SpriteHeight = 16.0f;
		m_BitmapId = L".\\Player\\Cast\\" + id + L".png";
	}
	else if( id.find(L"effect_") != std::wstring::npos )
	{
			m_SpriteWidth = 640.0f;
			m_SpriteHeight = 400.0f;
		m_BitmapId = L".\\Player\\Effect\\" + id + L".png";
	}
	else
		return false;
	
	if( m_Width < 0.0f )
	{
		std::wstring::size_type pos = std::wstring::npos;
		pos = m_BitmapId.find(L"left");
		if( pos != std::wstring::npos )
			m_BitmapId.replace( m_BitmapId.begin() + pos, m_BitmapId.begin() + pos + wcslen(L"left"), L"right" );
		else
		{
			pos = m_BitmapId.find(L"right");
			if( pos != std::wstring::npos )
				m_BitmapId.replace( m_BitmapId.begin() + pos, m_BitmapId.begin() + pos + wcslen(L"right"), L"left" );
		}
	}
	return true;
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
