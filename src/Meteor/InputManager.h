/**
 * @file	InputManager.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "IInputManager.h"

enum KEYSTATE
{
	KEY_DOWN,
	KEY_PRESSED,
	KEY_UP,
	KEY_NOTPRESSED,
};

class CInputManager : public IInputManager
{
public:
	// --------------------------------
	//	IInputManager interface
	// --------------------------------
	InputState GetKeyState( int key );
	InputState GetMouseState();

	// --------------------------------
	//	GetInstance
	// --------------------------------
	static CInputManager & GetInstance();

private:
	CInputManager() {};
	CInputManager( const CInputManager & );
	CInputManager & operator=( const CInputManager & );
};