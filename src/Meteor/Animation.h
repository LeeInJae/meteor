// author	Lee InJae (2013. 10. 27)

#pragma once

#include "IResource.h"

#include <string>
#include <vector>

class CSprite;

class CAnimation : public IResource
{
public:
	// --------------------------------
	//	CAnimation function
	// --------------------------------
	void SetSpeed( int fps );
	bool Update( float deltaTime );
	void Render();

	// --------------------------------
	//	IResourceManager interface
	// --------------------------------
	void Release();

private:
	friend class CResourceManager;

	CAnimation();
	virtual ~CAnimation();

	void AddSprite( CSprite * sprite );

	std::vector<CSprite *> m_Sprites;
	UINT		m_FrameNumber;
	int			m_FpsNumber;
	float		m_ElapsedTime;
};