#include "stdafx.h"
#include "GemStatusBar.h"
#include "ResourceManager.h"
#include "Sprite.h"
#include "SpriteInfo.h"


CGemStatusBar::CGemStatusBar(void)
	: m_StatusBar(nullptr)
{
}


CGemStatusBar::~CGemStatusBar(void)
{
	for ( auto gem : m_Gems )
		SafeRelease( gem );
	SafeRelease( m_StatusBar );
}

void CGemStatusBar::LoadSprites()
{
	//assert( m_StatusBar == nullptr );

	CSpriteInfo * spriteInfo = nullptr;

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_red_01" );
	m_Gems.push_back( spriteInfo->CreateSprite() );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_blue_01" );
	m_Gems.push_back( spriteInfo->CreateSprite() );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_green_01" );
	m_Gems.push_back( spriteInfo->CreateSprite() );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_yellow_01" );
	m_Gems.push_back( spriteInfo->CreateSprite() );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_black_01" );
	m_Gems.push_back( spriteInfo->CreateSprite() );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"ui_status_gem_01" );
	m_StatusBar = spriteInfo->CreateSprite();
	SafeRelease( spriteInfo );

	Position pos;
	pos.x = 0;
	pos.y = 330;
	m_StatusBar->SetPosition(pos);
	pos.x = -108;
	for( auto gem : m_Gems ){
		gem->SetPosition(pos);
		gem->SetImageWidth(40);
		gem->SetImageHeight(40);
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
	for ( auto gem : m_Gems )
	{
		gem->Render();
	}
}
