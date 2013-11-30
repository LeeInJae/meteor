#include "stdafx.h"
#include "CastUI.h"
#include "ResourceManager.h"
#include "Sprite.h"
#include "SpriteInfo.h"


void CCastUI::LoadSprites()
{
	assert( m_Sprites.size() == 0 );
	if ( m_Sprites.size() > 0 )
		return;

	CSpriteInfo * spriteInfo = nullptr;

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_red_01" );
	m_Sprites.push_back( spriteInfo->CreateSprite() );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_blue_01" );
	m_Sprites.push_back( spriteInfo->CreateSprite() );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_green_01" );
	m_Sprites.push_back( spriteInfo->CreateSprite() );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_yellow_01" );
	m_Sprites.push_back( spriteInfo->CreateSprite() );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_white_01" );
	m_Sprites.push_back( spriteInfo->CreateSprite() );
	SafeRelease( spriteInfo );

	spriteInfo = CResourceManager::GetInstance().GetSpriteInfo( L"cast_black_01" );
	m_Sprites.push_back( spriteInfo->CreateSprite() );
	SafeRelease( spriteInfo );
}


void CCastUI::Update( float deltaTime )
{
	for ( auto sprite : m_Sprites )
		SafeDelete( sprite );
}


void CCastUI::Render()
{
	if ( m_Sprites.size() == 0 )
		LoadSprites();

	Position position;
	position.x = -40.0f;
	position.y = 50.0f;
	std::vector<int> & casting = m_Player.GetCasting();

	for ( int cast : casting )
	{
		CSprite * sprite = m_Sprites[cast];
		sprite->SetPosition( position );
		sprite->Render();
		position.x += 20;
	}
}
