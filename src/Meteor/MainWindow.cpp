/**
 * @file	MainWindow.cpp
 * @brief
 * @author	Lee JinWoo
 *
 */

#include "stdafx.h"
#include "MainWindow.h"
#include "GameManager.h"

// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CMainWindow::CMainWindow(void)
	: m_GameManager( CGameManager::GetInstance() )
{
}

// ----------------------------------------------------------------
//	HandleMessage
// ----------------------------------------------------------------
LRESULT CMainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		m_GameManager.Release();
		PostQuitMessage(0);
		return 0;

	case WM_ERASEBKGND:
		return 1;

	default:
		return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
	}
}

// ----------------------------------------------------------------
//	GetInstance
// ----------------------------------------------------------------
int CMainWindow::RunGame()
{
	m_GameManager.Init();

	MSG msg = {};

	while ( msg.message != WM_QUIT )
	{
		if ( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if ( m_GameManager.Process() == false )
		{
			m_GameManager.Release();
			PostQuitMessage(0);
		}
	}

	return (int) msg.wParam;
}

// ----------------------------------------------------------------
//	GetInstance
// ----------------------------------------------------------------
CMainWindow & CMainWindow::GetInstance()
{
	static CMainWindow instance;
	return instance;
}
