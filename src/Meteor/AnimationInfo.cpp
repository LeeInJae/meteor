#include "stdafx.h"
#include "AnimationInfo.h"
#include "ResourceManager.h"
#include "Animation.h"
#include "SpriteInfo.h"

CAnimationInfo::CAnimationInfo(void)
	: m_Fps( 0 )
{
}


CAnimationInfo::~CAnimationInfo(void)
{
	m_SpriteId.clear();
}


bool CAnimationInfo::LoadResource( ResourceId id )
{
	if ( id.find(L"character") != std::wstring::npos
		|| id.find(L"effect") != std::wstring::npos )
	{
		if ( id.find(L"walk") != std::wstring::npos )
		{
			for( int idx = 1; idx < 4; ++idx)
			{
				wchar_t tmp[4];
				swprintf_s( tmp, L"_%02d", idx );
				m_SpriteId.push_back( id + tmp );
			}

			m_Fps = 8.0f;
		}
		else if ( id.find(L"flame_slash") != std::wstring::npos )
		{
			for( int idx = 1; idx < 7; ++idx)
			{
				wchar_t tmp[4];
				swprintf_s( tmp, L"_%02d", idx );
				m_SpriteId.push_back( id + tmp );
			}

			m_Fps = 10.0f;
		}
		else if ( id.find(L"slash") != std::wstring::npos )
		{
			for( int idx = 1; idx < 7; ++idx)
			{
				wchar_t tmp[4];
				swprintf_s( tmp, L"_%02d", idx );
				m_SpriteId.push_back( id + tmp );
			}

			m_Fps = 10.0f;
		}
		else if ( id.find(L"stiff") != std::wstring::npos )
		{
			m_SpriteId.push_back( id + L"_01" );
			m_Fps = 0.0f;
		}
	}
	else if ( id.find(L"skeleton_mage") != std::wstring::npos )
	{
		if ( id.find(L"walk") != std::wstring::npos )
		{
			for( int idx = 1; idx < 4; ++idx)
			{
				wchar_t tmp[4];
				swprintf_s( tmp, L"_%02d", idx );
				m_SpriteId.push_back( id + tmp );
			}
			m_Fps = 0.0f;
		}
		else if ( id.find(L"stiff") != std::wstring::npos )
		{
			m_SpriteId.push_back( id + L"_01" );
			m_Fps = 0.0f;
		}
	}

	return true;
}


// ----------------------------------------------------------------
//	CreateAnimation
// ----------------------------------------------------------------
CAnimation * CAnimationInfo::CreateAnimation()
{
	CAnimation * animation = new CAnimation();

	animation->SetSpeed( m_Fps );

	for ( auto spriteId : m_SpriteId )
	{
		CSpriteInfo * spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( spriteId );
		animation->AddSprite( spriteInfo->CreateSprite() );

		SafeRelease( spriteInfo );
	}

	return animation;
}


// ----------------------------------------------------------------
//	Release
// ----------------------------------------------------------------
void CAnimationInfo::Release()
{
	CResourceManager::GetInstance().ReleaseResource(this);
}
