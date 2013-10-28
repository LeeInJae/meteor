// Main.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Main.h"
#include "MainWindow.h"

// TODO: Remove test code
#include "Animation.h"
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

	// TODO: Remove test code
	CD2DRenderer::GetInstance().Init();
	CAnimation * animation = new CAnimation( 5 );
	CD2DText * text = new CD2DText();
	text->SetFont( L"±¼¸²", 12.f );
	
	DWORD startTime = timeGetTime();
	DWORD lastTime = startTime;

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
		if ( elapsedTime > ( 1000 / 100 ) )
		{
			animation->Update( static_cast<float>(currentTime - lastTime) );
			CD2DRenderer::GetInstance().Begin();
			CD2DRenderer::GetInstance().Clear();
			animation->Render();
//			std::wstring fps = std::to_wstring( 1000.0f / elapsedTime );
			wchar_t wstrbuf[16];
			swprintf_s( wstrbuf, L"Fps: %.2f",  1000.0f / elapsedTime );
			text->SetText( std::wstring(wstrbuf) );
			text->Render();
			CD2DRenderer::GetInstance().End();
			lastTime = currentTime;
		}
	}

	return (int) msg.wParam;
}
