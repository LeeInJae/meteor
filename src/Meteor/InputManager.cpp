/**
 * @file	InputManager.cpp
 * @brief
 * @author	Lee JinWoo
 *
 */

#include "stdafx.h"
#include "InputManager.h"


// ----------------------------------------------------------------
//	UpdateKeyState
// ----------------------------------------------------------------
void CInputManager::UpdateKeyState()
{
	for ( int i = 0; i < 256; i++ )
	{
		m_PreviousKeyState[i] = m_CurrentKeyState[i];

		if( ::GetKeyState(i) & 0x8000 )
			m_CurrentKeyState[i] = true;
		else
			m_CurrentKeyState[i] = false;
	}
}

// ----------------------------------------------------------------
//	GetKeyState
// ----------------------------------------------------------------
InputState CInputManager::GetKeyState( int key )
{
	if ( m_PreviousKeyState[key] == false && m_CurrentKeyState[key] == true )
	{
		return INPUT_DOWN;
	}
	else if ( m_PreviousKeyState[key] == true && m_CurrentKeyState[key] == true )
	{
		return INPUT_PRESSED;
	}
	else if ( m_PreviousKeyState[key] == true && m_CurrentKeyState[key] == false )
	{
		return INPUT_UP;
	}
	
	return INPUT_NOTPRESSED;
}

// ----------------------------------------------------------------
//	GetMouseState
// ----------------------------------------------------------------
InputState CInputManager::GetMouseState()
{
	return INPUT_NOTPRESSED;
}

// ----------------------------------------------------------------
//	GetInstance
// ----------------------------------------------------------------
CInputManager & CInputManager::GetInstance()
{
	static CInputManager instance;
	return instance;
}
