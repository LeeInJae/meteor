
#pragma once
#include "Scene.h"
#include "PC.h"
#include "GemStatusBar.h"

class CZone;
class CCastUI;

class CPlayScene : public CScene
{
public:
	CPlayScene();
	virtual ~CPlayScene();

	bool Update( float deltaTime );
	void Render();

private:
	Position	m_CameraPosition;
	CPC			m_PlayerCharacter;
	CZone *		m_Zone;
	CCastUI *	m_CastingUI;
	CGemStatusBar * m_GemStatusBar;
};