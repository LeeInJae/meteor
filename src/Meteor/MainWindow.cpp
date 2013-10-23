/**
 * @file	MainWindow.cpp
 * @brief
 * @author	Lee JinWoo
 *
 */

#include "stdafx.h"
#include "MainWindow.h"

CMainWindow::CMainWindow(void)
	: m_SceneManager(nullptr)
	, m_Renderer(nullptr)
{
}

CMainWindow::~CMainWindow(void)
{
}

LRESULT CMainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		//if ( FAILED(m_SceneManager->Init() ) )
		//{
		//	return -1;
		//}
		return 0;

	case WM_DESTROY:
		//m_SceneManager->Release();
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	case WM_DISPLAYCHANGE:
		{
			PAINTSTRUCT ps;
			BeginPaint(m_hwnd, &ps);
			//m_SceneManager->RenderScene();
			EndPaint(m_hwnd, &ps);
		}
		return 0;

	case WM_ERASEBKGND:
		return 1;

	default:
		return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
	}
}
