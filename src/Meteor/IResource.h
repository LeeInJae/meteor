// @author	Lee JinWoo (2013.10.20)
#pragma once

#include "ResourceId.h"

class IResource
{
	friend class CResourceManager;
protected:
	IResource() : m_Loaded(false), m_ReferenceCount(0) {}
	virtual ~IResource() {}

	virtual void Release() = 0;

private:
	ResourceId	m_Key;
	bool		m_Loaded;
	UINT		m_ReferenceCount;
};
