// author	Lee InJae (2013. 10. 27)

#pragma once

#include "Sprite.h"

class CAnimation
{
public:
	CAnimation();
	CAnimation( int fpsNumber );

	virtual ~CAnimation();

	bool Update( float deltaTime );
	bool Render();

private:
	std::vector<CSprite *> m_Sprites;
	float	 m_ElapsedTime;
	UINT	 m_FrameNumber;
	int		 m_FpsNumber;
};