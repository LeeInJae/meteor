#include "stdafx.h"
#include "PrintLog.h"
#include <stdio.h>


CPrintLog::CPrintLog(void)
{
}


CPrintLog::~CPrintLog(void)
{
}

void CPrintLog::Init()
{
	AllocConsole();
	FILE* pStream;
	freopen_s(&pStream, "CONOUT$", "wt", stdout);
}

void CPrintLog::Release()
{
	FreeConsole();
}