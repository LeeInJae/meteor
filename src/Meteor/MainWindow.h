/**
 * @file	MainWindow.h
 * @brief
 * @author	Lee JinWoo
 *
 */

#pragma once

#include "BaseWindow.h"
#include "ISceneManager.h"
#include "IRenderer.h"

static const WCHAR WINDOW_NAME[] = L"Meteor";

class CMainWindow : public CBaseWindow<CMainWindow>
{
public:
	CMainWindow();
	~CMainWindow();

	PCWSTR	ClassName() const { return WINDOW_NAME; }
	LRESULT	HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:
	ISceneManager * m_SceneManager;
	IRenderer * m_Renderer;
};
