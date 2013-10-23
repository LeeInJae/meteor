/**
 * @file	InputManager.cpp
 * @brief
 * @author	Lee JinWoo
 *
 */

#include "stdafx.h"
#include "InputManager.h"

// ----------------------------------------------------------------
//	GetKeyState
// ----------------------------------------------------------------
InputState CInputManager::GetKeyState( int key )
{
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
