#include "stdafx.h"
#include "HpUI.h"
#include "ResourceManager.h"
#include "Sprite.h"
#include "SpriteInfo.h"
#include "Character.h"


CHpUI::CHpUI( CCharacter * character )
	 : m_Character(character)
{
	m_Bar.SetFill( true );
	m_Bar.SetColor( 0.0f, 0.7f, 0.1f, 1.0f );
	m_Rect.SetRect( -30.0f, -60.0f, 30.0f, -50.0f );
}


void CHpUI::Update( float deltaTime )
{
}


void CHpUI::SetPosition( const Position & cameraPosition )
{
	float barLength = 60.0f * m_Character->GetHp() / m_Character->GetMaxHp();
	m_Bar.SetRect( -30.0f, -60.0f, -30.0f + barLength, -50.0f );

	Position position = m_Character->GetPosition();
	position.x -= cameraPosition.x;
	position.y -= cameraPosition.y;
	m_Rect.SetPosition( position );
	m_Bar.SetPosition( position );
}


void CHpUI::Render()
{
	m_Bar.Render();
	m_Rect.Render();
}
