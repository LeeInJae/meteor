// @author	Lee JinWoo (2013.10.20)
#pragma once

#include "ResourceId.h"

class IResource
{
public:
	IResource() : m_Id(L""), m_Loaded(false), m_ReferenceCount(0) {}
	virtual ~IResource() {}

	virtual bool LoadResource( ResourceId id ) = 0;
	virtual void Release() = 0;

	ResourceId	m_Id;
	bool		m_Loaded;
	UINT		m_ReferenceCount;
};
