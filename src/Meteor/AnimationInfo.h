#pragma once

#include "IResource.h"
#include <vector>

class CAnimation;

// ----------------------------------------------------------------
//	CAnimationInfo
// ----------------------------------------------------------------
class CAnimationInfo : public IResource
{
public:
	CAnimationInfo(void);
	~CAnimationInfo(void);

	CAnimation * CreateAnimation();

	// --------------------------------
	//	IResource interface
	// --------------------------------
	bool LoadResource( ResourceId id );
	void Release();

private:
	float					m_Fps;
	std::vector<ResourceId>	m_SpriteId;
};
