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
	void UpdateKeyState();

	// --------------------------------
	//	IInputManager interface
	// --------------------------------
	InputState GetKeyState( int key );
	InputState GetMouseState();
	void BlockKeyState( int key );

	// --------------------------------
	//	GetInstance
	// --------------------------------
	static CInputManager & GetInstance();

private:
	CInputManager() {};
	CInputManager( const CInputManager & );
	CInputManager & operator=( const CInputManager & );

	bool m_PreviousKeyState[256];
	bool m_CurrentKeyState[256];
	bool m_BlockKeyState[256];
};