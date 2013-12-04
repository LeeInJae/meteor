#include "stdafx.h"
#include "HpUI.h"
#include "ResourceManager.h"
#include "Sprite.h"
#include "SpriteInfo.h"
#include "Character.h"


CHpUI::CHpUI( CCharacter * character )
	 : m_Character(character)
{
	m_Rect.SetRect( -30.0f, -60.0f, 30.0f, -50.0f );
}


void CHpUI::Update( float deltaTime )
{
}


void CHpUI::SetPosition( const Position & cameraPosition )
{
	Position position = m_Character->GetPosition();
	position.x -= cameraPosition.x;
	position.y -= cameraPosition.y;
	m_Rect.SetPosition( position );
}


void CHpUI::Render()
{
	m_Rect.Render();
}
