#pragma once
#include "uiobject.h"
#include "Animation.h"

class CGemStatusBar :
	public CUIObject
{
public:
	CGemStatusBar(void);
	~CGemStatusBar(void);

	void LoadSprites();

	// --------------------------------
	//	IRenderObject
	// --------------------------------
	void Update( float deltaTime );
	void Render();

private:
	std::list<CSprite *> m_Gems;
	CSprite * m_StatusBar;
};

