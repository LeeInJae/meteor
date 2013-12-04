#pragma once

#include "UIObject.h"
#include "PC.h"

class CCastUI final : public CUIObject
{
public:
	CCastUI( CPC & player ) : m_Player(player) {}
	~CCastUI(void);

	void LoadSprites();

	// --------------------------------
	//	IRenderObject
	// --------------------------------
	void Update( float deltaTime );
	void Render();

private:
	CPC & m_Player;
	//std::vector<CSprite *> m_Sprites;
	std::map<std::string, CSprite *> m_Sprites;
};
