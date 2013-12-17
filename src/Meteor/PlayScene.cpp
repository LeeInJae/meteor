#include "stdafx.h"
#include "PlayScene.h"
#include "Zone.h"
#include "CastUI.h"
#include "InputManager.h"
#include "ResourceManager.h"

CPlayScene::CPlayScene(void)
	: m_Zone( nullptr )
{
	m_CameraPosition.x = 0.0f;
	m_CameraPosition.y = 0.0f;

	m_PlayerCharacter.LoadAnimation();
	m_PlayerCharacter.SetHp( 18.0f );
	m_PlayerCharacter.SetMaxHp( 20.0f );
	m_CastingUI = new CCastUI( m_PlayerCharacter );
	m_GemStatusBar = new CGemStatusBar();

	CZoneInfo * zoneInfo = CResourceManager::GetInstance().GetZoneInfo( L"zone_village" );
	m_Zone = zoneInfo->CreateZone();
	m_Zone->Enter( &m_PlayerCharacter, nullptr );
	SafeRelease( zoneInfo );
}


CPlayScene::~CPlayScene(void)
{
	SafeDelete( m_Zone );
	SafeDelete( m_CastingUI );
}


bool CPlayScene::Update( float deltaTime )
{
	if ( CInputManager::GetInstance().GetKeyState( VK_LEFT ) & INPUT_PRESSED )
	{
		if ( CInputManager::GetInstance().GetKeyState( VK_UP ) & INPUT_PRESSED ){
			m_PlayerCharacter.SetDirection( UP_LEFT );
		}
		else if ( CInputManager::GetInstance().GetKeyState( VK_DOWN ) & INPUT_PRESSED ){
			m_PlayerCharacter.SetDirection( DOWN_LEFT );
		}
		else{
			m_PlayerCharacter.SetDirection( LEFT );
		}
		m_PlayerCharacter.SetStatus( CHARACTER_WALK );
	}
	else if ( CInputManager::GetInstance().GetKeyState( VK_RIGHT ) & INPUT_PRESSED )
	{
		if ( CInputManager::GetInstance().GetKeyState( VK_UP ) & INPUT_PRESSED ){
			m_PlayerCharacter.SetDirection( UP_RIGHT );
		}
		else if ( CInputManager::GetInstance().GetKeyState( VK_DOWN ) & INPUT_PRESSED ){
			m_PlayerCharacter.SetDirection( DOWN_RIGHT );
		}
		else{
			m_PlayerCharacter.SetDirection( RIGHT );
		}
		m_PlayerCharacter.SetStatus( CHARACTER_WALK );
	}

	else if ( CInputManager::GetInstance().GetKeyState( VK_UP ) & INPUT_PRESSED )
	{
		m_PlayerCharacter.SetDirection( UP );
		m_PlayerCharacter.SetStatus( CHARACTER_WALK );
	}

	else if ( CInputManager::GetInstance().GetKeyState( VK_DOWN ) & INPUT_PRESSED )
	{
		m_PlayerCharacter.SetDirection( DOWN );
		m_PlayerCharacter.SetStatus( CHARACTER_WALK );
	}
	else
	{
		m_PlayerCharacter.SetStatus( CHARACTER_STAND );
	}

	char keymap[] = { 'Q', 'W', 'E', 'R', 'T' };
	std::string gemMap[] = {
		"Red",
		"Blue",
		"Green",
		"Yellow",
		"Black"
	};
	int index = 0;
	for ( auto key : keymap )
	{
		if ( ( CInputManager::GetInstance().GetKeyState( key ) & INPUT_DOWN ) )
			m_PlayerCharacter.Cast( gemMap[index] );
		++ index;
	}

	

	if ( CInputManager::GetInstance().GetKeyState( VK_SPACE ) & INPUT_DOWN )
		m_PlayerCharacter.Action();


	m_PlayerCharacter.Update( deltaTime );
	m_CameraPosition = m_PlayerCharacter.GetPosition();
	m_Zone->Update( deltaTime, m_CameraPosition );

	return true;
}

void CPlayScene::Render()
{
	m_Zone->Render( m_CameraPosition );
	m_CastingUI->Render();
	m_GemStatusBar->Render();
}
