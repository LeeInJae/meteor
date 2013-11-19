#include "stdafx.h"
#include "Fps.h"


// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CFps::CFps(void)
	: m_ElapsedTimeSum(0)
	, m_ElapsedTimeSum1(0)
	, m_FrameCount(0)
	, m_FrameCount1(0)
	, m_FramePerSecond( 0.0f )
{
	m_Text.LoadResource( L"FPS" );
	m_Text.SetFont( L"±¼¸²", 12.f );
}


// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
CFps::~CFps(void)
{
}


// ----------------------------------------------------------------
//	Update
// ----------------------------------------------------------------
bool CFps::Update( float elapsedTime )
{
	m_ElapsedTimeSum += elapsedTime;
	m_FrameCount++;
	if ( m_ElapsedTimeSum >= 1.0f )
	{
		m_FramePerSecond = ( m_FrameCount + m_FrameCount1 ) / ( m_ElapsedTimeSum + m_ElapsedTimeSum1 );
		m_ElapsedTimeSum1 = m_ElapsedTimeSum;
		m_ElapsedTimeSum = 0;
		m_FrameCount1 = m_FrameCount;
		m_FrameCount = 0;
	}

	return true;
}

// ----------------------------------------------------------------
//	Render
// ----------------------------------------------------------------
void CFps::Render()
{
	wchar_t wstrbuf[16];
	swprintf_s( wstrbuf, L"Fps: %.2f",  m_FramePerSecond );
	m_Text.SetText( std::wstring(wstrbuf) );
	m_Text.Render();
}
