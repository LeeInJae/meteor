#pragma once

#include "IRenderobject.h"

class CUIObject : public IRenderObject
{
public:
	CUIObject() : IRenderObject( ZINDEX_UIOBJECT ) {}
	virtual ~CUIObject() {}

	// --------------------------------
	//	IRenderObject
	// --------------------------------
	virtual void Update( float deltaTime ) = 0;
	virtual void Render() = 0;
};
