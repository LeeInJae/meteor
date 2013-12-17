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
	void SetSpeed( float fps ) { m_Fps = fps; }
	void SetPosition( const Position & position, const Position & cameraPosition );
	void SetRotation( float rotation )			{ m_Rotation = rotation; }
	void AddSprite( CSprite * sprite );
	bool Update( float deltaTime );
	void Render() const;
	void Play( int frameNumber, bool loop );
	void Play( bool loop );
	void Stop( int frameNumber );
	void Stop();

private:
	std::vector<CSprite *> m_Sprites;
	UINT		m_FrameNumber;
	float		m_Fps;
	bool		m_Stop;
	bool		m_Loop;
	Position	m_Position;
	float		m_ElapsedTime;
	float		m_Rotation;
};