#include "stdafx.h"
#include "Scene.h"
#include "InputManager.h"
#include "ResourceManager.h"

CScene::CScene(void)
	: m_Zone( nullptr )
{
	m_CameraPosition.x = 0.0f;
	m_CameraPosition.y = 0.0f;

	m_PlayerCharacter.LoadAnimation();

	CZoneInfo * zoneInfo = CResourceManager::GetInstance().GetZoneInfo( L"zone_village" );
	m_Zone = zoneInfo->CreateZone();
	m_Zone->Enter( &m_PlayerCharacter, nullptr );
	SafeRelease( zoneInfo );
}


CScene::~CScene(void)
{
	SafeDelete( m_Zone );
}


bool CScene::Update( float deltaTime )
{
	if ( CInputManager::GetInstance().GetKeyState( VK_LEFT ) & INPUT_PRESSED )
	{
		m_PlayerCharacter.SetDirection( LEFT );
		m_PlayerCharacter.SetStatus( CHARACTER_WALK );
	}
	else if ( CInputManager::GetInstance().GetKeyState( VK_RIGHT ) & INPUT_PRESSED )
	{
		m_PlayerCharacter.SetDirection( RIGHT );
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


	if ( CInputManager::GetInstance().GetKeyState( VK_SPACE ) & INPUT_PRESSED )
	{
		// m_PlayerCharacter.Action();
	}


	m_PlayerCharacter.Update( deltaTime );
	m_CameraPosition = m_PlayerCharacter.GetPosition();
	m_Zone->Update( deltaTime, m_CameraPosition );

	return true;
}

void CScene::Render()
{
	m_Zone->Render( m_CameraPosition );
}
