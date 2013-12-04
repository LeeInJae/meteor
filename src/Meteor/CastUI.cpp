#include "stdafx.h"
#include "CastUI.h"
#include "ResourceManager.h"
#include "Sprite.h"
#include "SpriteInfo.h"


CCastUI::~CCastUI()
{
	for ( auto sprite : m_Sprites )
		SafeDelete( sprite.second );
}


void CCastUI::LoadSprites()
{
	assert( m_Sprites.size() == 0 );
	if ( m_Sprites.size() > 0 )
		return;

	CSpriteInfo * spriteInfo = nullptr;

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_red_01" );
	m_Sprites["Red"] = spriteInfo->CreateSprite();
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_blue_01" );
	m_Sprites["Blue"] = spriteInfo->CreateSprite();
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_green_01" );
	m_Sprites["Green"] = spriteInfo->CreateSprite();
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_yellow_01" );
	m_Sprites["Yellow"] = spriteInfo->CreateSprite();
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_white_01" );
	m_Sprites["White"] = spriteInfo->CreateSprite();
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_black_01" );
	m_Sprites["Black"] = spriteInfo->CreateSprite();
	SafeRelease( spriteInfo );
}


void CCastUI::Update( float deltaTime )
{
}


void CCastUI::Render()
{
	if ( m_Sprites.size() == 0 )
		LoadSprites();

	Position position;
	position.x = -40.0f;
	position.y = 50.0f;
	std::list<std::string> & casting = m_Player.GetCasting();

	for ( std::string cast : casting )
	{
		CSprite * sprite = m_Sprites[cast];
		sprite->SetPosition( position );
		sprite->Render();
		position.x += 20;
	}
}
