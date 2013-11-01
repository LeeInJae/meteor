#include "stdafx.h"
#include "Scene.h"
#include "InputManager.h"

CScene::CScene(void)
{
	m_PlayerCharacter.LoadAnimation();
}

CScene::~CScene(void)
{
}
	
void CScene::Update( float deltaTime )
{
	switch ( CInputManager::GetInstance().GetKeyState( VK_LEFT ) )
	{
	case INPUT_DOWN:
		m_PlayerCharacter.SetDirection( LEFT );
		m_PlayerCharacter.SetStatus( WALK );
		break;

	case INPUT_UP:
		m_PlayerCharacter.SetStatus( STAND );
		break;

	default:
		break;
	}

	switch ( CInputManager::GetInstance().GetKeyState( VK_RIGHT ) )
	{
	case INPUT_DOWN:
		m_PlayerCharacter.SetDirection( RIGHT );
		m_PlayerCharacter.SetStatus( WALK );
		break;

	case INPUT_UP:
		m_PlayerCharacter.SetStatus( STAND );
		break;

	default:
		break;
	}

	switch ( CInputManager::GetInstance().GetKeyState( VK_UP ) )
	{
	case INPUT_DOWN:
		m_PlayerCharacter.SetDirection( UP );
		m_PlayerCharacter.SetStatus( WALK );
		break;

	case INPUT_UP:
		m_PlayerCharacter.SetStatus( STAND );
		break;

	default:
		break;
	}

	switch( CInputManager::GetInstance().GetKeyState( VK_DOWN ) )
	{
	case INPUT_DOWN:
		m_PlayerCharacter.SetDirection( DOWN );
		m_PlayerCharacter.SetStatus( WALK );
		break;

	case INPUT_UP:
		m_PlayerCharacter.SetStatus( STAND );
		break;

	default:
		break;
	}
	m_PlayerCharacter.Update( deltaTime );
}

void CScene::Render()
{
	m_PlayerCharacter.Render();
}
