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

	bool CAnimationInfo::LoadResource( ResourceId id );
	CAnimation * CreateAnimation();

	// --------------------------------
	//	IResource interface
	// --------------------------------
	virtual void Release();

private:
	UINT					m_Fps;
	std::vector<ResourceId>	m_SpriteId;
};
