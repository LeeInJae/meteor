#include "stdafx.h"
#include "GemStatusBar.h"
#include "ResourceManager.h"
#include "Sprite.h"
#include "SpriteInfo.h"
#include "PC.h"


CGemStatusBar::CGemStatusBar( CPC & player )
	: m_StatusBar(nullptr)
	, m_Player(player)
{
	m_Text.LoadResource(L"cool_time");
	m_Text.SetFont( L"±¼¸²", 16.f );
}


CGemStatusBar::~CGemStatusBar(void)
{
	SafeRelease( m_StatusBar );
}

void CGemStatusBar::LoadSprites()
{
	//assert( m_StatusBar == nullptr );

	CSpriteInfo * spriteInfo = nullptr;

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_red_01" );
	m_Gems.push_back( GemMatch( "Red", spriteInfo->CreateSprite() ) );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_blue_01" );
	m_Gems.push_back( GemMatch( "Blue", spriteInfo->CreateSprite() ) );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_green_01" );
	m_Gems.push_back( GemMatch( "Green", spriteInfo->CreateSprite() ) );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_yellow_01" );
	m_Gems.push_back( GemMatch( "Yellow", spriteInfo->CreateSprite() ) );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_black_01" );
	m_Gems.push_back( GemMatch( "Black", spriteInfo->CreateSprite() ) );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"ui_status_gem_01" );
	m_StatusBar = spriteInfo->CreateSprite();
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"ui_status_gem_cool_01" );
	m_GemCool = spriteInfo->CreateSprite();
	SafeRelease( spriteInfo );

	Position pos;
	pos.x = 0;
	pos.y = 330;
	m_StatusBar->SetPosition(pos);
	pos.x = -108;
	for( auto gem : m_Gems ){
		gem.m_Sprite->SetPosition(pos);
		gem.m_Sprite->SetImageWidth(40);
		gem.m_Sprite->SetImageHeight(40);
		pos.x += 54;
	}
}

void CGemStatusBar::Update( float deltaTime )
{

}

void CGemStatusBar::Render()
{
	if(m_StatusBar == nullptr)
		LoadSprites();
	m_StatusBar->Render();

	Position pos;
	pos.x = -108;
	pos.y = 330;
	for ( auto gem : m_Gems )
	{
		gem.m_Sprite->Render();
		float coolTime = m_Player.GetCoolTime( gem.m_Name );
		if( coolTime > 0 )
		{
			m_GemCool->SetPosition( pos );
			m_GemCool->Render();
			wchar_t wstrbuf[5];
			swprintf_s( wstrbuf, L"%.1f", coolTime );
			m_Text.SetText( std::wstring(wstrbuf) );
			m_Text.SetPosition( pos.x + 491, pos.y + 355 );
			m_Text.Render();
		}
		pos.x += 54;
	}
}

GemMatch::~GemMatch()
{
	SafeRelease(m_Sprite);
}
