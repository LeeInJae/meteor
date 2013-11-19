#pragma once

#include "D2DText.h"

class CFps
{
public:
	CFps(void);
	~CFps(void);

	double	GetFps() { return m_FramePerSecond; }
	bool	Update( float elapsedTime );
	void	Render();

private:
	float	m_ElapsedTimeSum;
	float	m_ElapsedTimeSum1;
	float	m_FrameCount;
	float	m_FrameCount1;
	float	m_FramePerSecond;

	CD2DText	m_Text;
};
