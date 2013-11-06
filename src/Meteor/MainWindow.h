/**
 * @file	MainWindow.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "BaseWindow.h"
#include "IGameManager.h"

static const WCHAR WINDOW_NAME[] = L"Meteor";

class CMainWindow : public CBaseWindow<CMainWindow>
{
public:
	// --------------------------------
	//	CBaseWindow interface
	// --------------------------------
	PCWSTR	ClassName() const { return WINDOW_NAME; }
	LRESULT	HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	// --------------------------------
	//	RunGame
	// --------------------------------
	int RunGame();

	// --------------------------------
	//	GetInstance
	// --------------------------------
	static CMainWindow & GetInstance();

protected:
	CMainWindow();
	CMainWindow( const CMainWindow & );
	CMainWindow & operator=( const CMainWindow & );

	IGameManager & m_GameManager;
};
