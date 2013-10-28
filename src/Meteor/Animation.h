/**
 * @file	Animation.h
 * @brief
 * @author	Lee InJae
 *
 */

#pragma once

#include "Sprite.h"

#include <vector>

class CAnimation
{
public:
	CAnimation();
	CAnimation( int frameSetNumber );

	virtual ~CAnimation();

	bool Update( float deltaTime );
	bool Render();

private:
	std::vector<CSprite *> m_Sprites;
	float m_ElapsedTime;
	unsigned int   m_FrameNumber;
	int   m_FrameSetNumber;
};