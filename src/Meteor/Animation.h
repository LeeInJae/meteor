// author	Lee InJae (2013. 10. 27)

#pragma once

#include "IResource.h"
#include "Position.h"

#include <string>
#include <vector>

class CSprite;

class CAnimation
{
public:
	CAnimation();
	virtual ~CAnimation();
	// --------------------------------
	//	CAnimation function
	// --------------------------------
	void SetSpeed( int fps ) { m_Fps = fps; }
	void SetPosition( Position & position, Position & cameraPosition );
	void AddSprite( CSprite * sprite );
	bool Update( float deltaTime );
	void Render();

private:

	std::vector<CSprite *> m_Sprites;
	UINT		m_FrameNumber;
	int			m_Fps;
	Position	m_Position;
	float		m_ElapsedTime;
};