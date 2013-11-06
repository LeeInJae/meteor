// Main.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Main.h"
#include "MainWindow.h"

#ifdef _DEBUG
#include "PrintLog.h" // 디버그용 콘솔창
#endif // _DEBUG

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

#ifdef _DEBUG // 디버그용 콘솔창
	CPrintLog pPrintLog;
	pPrintLog.Init();
	printf_s("CONSOLE WINDOW OPENED\n");
#endif // _DEBUG

	CMainWindow & window = CMainWindow::GetInstance();

	if ( ! window.Create( L"Meteor", WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX ) )
		return 0;

	window.ShowWindow( nCmdShow );

	return window.RunGame();
}
