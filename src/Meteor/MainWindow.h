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

	static CMainWindow*		GetInstance();
	static void				ReleaseInstance();

	inline IRenderer* GetRenderer() const { return m_Renderer; }
	inline HWND GetHWND() const { return m_Hwnd; }
	inline HINSTANCE GetHandleInstance() const { return m_hInstance; }
	//inline const wchar_t* GetTitle() const { return m_Title; }
	//inline int GetScreenWidth() const { return m_ScreenWidth; }
	//inline int GetScreenHeight() const { return m_ScreenHeight; }
	inline RendererStatus GetRendererStatus() const { return m_RendererStatus; }

	inline float GetFPS() const { return m_Fps; }
	inline float GetElapsedTime() const { return m_ElapsedTime; }
	inline float GetDeltaTime() const { return m_DeltaTime; }

protected:
	ISceneManager * m_SceneManager;
	IRenderer * m_Renderer;

public:
	CMainWindow();
	~CMainWindow();
	static CMainWindow* m_pInstance;

	float m_Fps;
	float m_ElapsedTime;
	float m_DeltaTime;
	HWND m_Hwnd;
	HINSTANCE m_hInstance;
	RendererStatus m_RendererStatus;
	int m_PrevTime;
	int m_NowTime;

};
