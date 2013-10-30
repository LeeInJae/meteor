// Main.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Main.h"
#include "MainWindow.h"

#ifdef _DEBUG
#include "PrintLog.h" // 디버그용 콘솔창
#endif // _DEBUG

// TODO: Remove test code
#include "Scene.h"
#include "D2DText.h"

#include <Mmsystem.h>

#pragma comment(lib, "winmm")
#pragma comment(lib, "d2d1")
#pragma comment(lib, "dwrite.lib")

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	CMainWindow & window = CMainWindow::GetInstance();

	if ( ! window.Create( L"Meteor", WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX ) )
		return 0;

	window.ShowWindow( nCmdShow );

#ifdef _DEBUG // 디버그용 콘솔창
	CPrintLog pPrintLog;
	pPrintLog.Init();
	printf_s("CONSOLE WINDOW OPENED\n");
#endif // _DEBUG

	// TODO: Remove test code
	CD2DRenderer::GetInstance().Init();
	CScene scene;
	CD2DText * text = new CD2DText();
	text->SetFont( L"굴림", 12.f );

	// FPS Calculation
	DWORD startTime = timeGetTime();
	DWORD lastTime = startTime;

	DWORD elapsedTimeSum = 0;
	DWORD logLotateCount = 0;
	double framePerSecond = 0;

	MSG msg = {};

	// Main message loop:
	while ( msg.message != WM_QUIT )
	{
		if ( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD currentTime = timeGetTime();
		DWORD elapsedTime = currentTime - lastTime;

		elapsedTimeSum += elapsedTime;
		logLotateCount++;
		if ( elapsedTimeSum >= 500 )
		{
			framePerSecond = ( logLotateCount * 1000.0f ) / elapsedTimeSum;
			elapsedTimeSum = 0;
			logLotateCount = 0;
		}

		//if ( elapsedTime > ( 1000 / 1000 ) )
		{
			scene.Update( static_cast<float>(currentTime - lastTime) );
			CD2DRenderer::GetInstance().Begin();
			CD2DRenderer::GetInstance().Clear();
			scene.Render();

			wchar_t wstrbuf[16];
			swprintf_s( wstrbuf, L"Fps: %.2f",  framePerSecond );
			text->SetText( std::wstring(wstrbuf) );
			text->Render();

			CD2DRenderer::GetInstance().End();
			lastTime = currentTime;
		}
	}

	return (int) msg.wParam;
}
