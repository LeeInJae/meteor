// @author	Lee JinWoo (2013.10.20)
#pragma once

class IResource
{
	friend class IResourceManager;
public:
	IResource() : m_Loaded(false), m_ReferenceCount(0) {}
	virtual ~IResource() {}

	virtual void Release() = 0;

private:
	bool	m_Loaded;
	UINT	m_ReferenceCount;
};
