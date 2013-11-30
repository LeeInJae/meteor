#pragma once

#include "IEventSubject.h"
#include "IEventListener.h"

typedef UINT				ZINDEX;
#define ZINDEX_MAP			0x00000000
#define ZINDEX_GAMEOBJECT	0x00400000
#define ZINDEX_UIOBJECT		0x00800000

class IRenderObject
{
public:
	IRenderObject() : m_ZIndex(0) {}
	IRenderObject( ZINDEX zIndex ) : m_ZIndex( zIndex ) {}
	virtual ~IRenderObject() {}

	ZINDEX GetZIndex() const			{ return m_ZIndex; }
	void SetZIndex( ZINDEX zIndex )	{ m_ZIndex = zIndex; }

	virtual void Update( float deltaTime ) = 0;
	virtual void Render() = 0;

protected:
	ZINDEX m_ZIndex;
};
