#pragma once

#include "D2DText.h"

class CFps
{
public:
	CFps(void);
	~CFps(void);

	double	GetFps() { return m_FramePerSecond; }
	bool	Update( int elapsedTime );
	void	Render();

private:
	DWORD	m_ElapsedTimeSum;
	DWORD	m_ElapsedTimeSum1;
	DWORD	m_FrameCount;
	DWORD	m_FrameCount1;
	double	m_FramePerSecond;

	CD2DText	m_Text;
};
