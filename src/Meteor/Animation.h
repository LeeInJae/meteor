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
	// --------------------------------
	//	CAnimation function
	// --------------------------------
	void SetSpeed( int fps ) { m_Fps = fps; }
	void SetPosition( Position position ) { m_Position = position; }
	bool Update( float deltaTime );
	void Render();
	void Release();

private:
	friend class CAnimationInfo;
	CAnimation();
	virtual ~CAnimation();
	void AddSprite( CSprite * sprite );

	std::vector<CSprite *> m_Sprites;
	UINT		m_FrameNumber;
	int			m_Fps;
	Position	m_Position;
	float		m_ElapsedTime;
};