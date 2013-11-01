// author	Lee InJae (2013. 10. 27)

#pragma once

#include "Sprite.h"

#include <string>
#include <vector>

class CAnimation
{
public:
	CAnimation( std::string key, int fpsNumber = 10 );

	virtual ~CAnimation();
	
	bool LoadSprite();
	bool Update( float deltaTime );
	bool Render();

private:
	std::vector<CSprite *> m_Sprites;
	std::string m_AnimationKey;
	UINT		m_FrameNumber;
	int			m_FpsNumber;
	float		m_ElapsedTime;
};