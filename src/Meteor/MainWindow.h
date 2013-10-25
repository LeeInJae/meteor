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
	PCWSTR	ClassName() const { return WINDOW_NAME; }
	LRESULT	HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	static CMainWindow & GetInstance();

	IRenderer * GetRenderer() const { return m_Renderer; }

	float GetFPS() const { return m_Fps; }
	float GetElapsedTime() const { return m_ElapsedTime; }
	float GetDeltaTime() const { return m_DeltaTime; }

protected:
	CMainWindow();
	CMainWindow( const CMainWindow & );
	CMainWindow & operator=( const CMainWindow & );

	ISceneManager *	m_SceneManager;
	IRenderer *		m_Renderer;

	float m_Fps;
	float m_ElapsedTime;
	float m_DeltaTime;
	int m_PrevTime;
	int m_NowTime;
};
