#pragma once
#include "uiobject.h"
#include "Animation.h"
#include "D2DText.h"

class GemMatch
{
public:
	GemMatch( std::string name, CSprite * sprite )
		: m_Name(name)
		, m_Sprite(sprite) {}
	~GemMatch();

	std::string m_Name;
	CSprite * m_Sprite;
};
class CPC;

class CGemStatusBar :
	public CUIObject
{
public:
	CGemStatusBar( CPC & player );
	~CGemStatusBar(void);

	void LoadSprites();

	// --------------------------------
	//	IRenderObject
	// --------------------------------
	void Update( float deltaTime );
	void Render();

private:
	std::list<GemMatch>		m_Gems;
	CSprite *				m_StatusBar;
	CSprite *				m_GemCool;
	CD2DText				m_Text;
	CPC &					m_Player;
};

