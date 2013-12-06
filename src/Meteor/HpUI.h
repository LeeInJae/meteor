#pragma once

#include "UIObject.h"
#include "D2DRect.h"

class CCharacter;

class CHpUI : public CUIObject
{
public:
	CHpUI( CCharacter * character );
	~CHpUI(void) {}

	void SetPosition( const Position & cameraPosition );

	// --------------------------------
	//	IRenderObject
	// --------------------------------
	void Update( float deltaTime );
	void Render();

private:
	CCharacter *	m_Character;
	CD2DRect		m_Rect;
	CD2DRect		m_Bar;
};
