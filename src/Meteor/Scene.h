
#pragma once
#include "PC.h"
#include "Zone.h"
#include "CastUI.h"

class CScene
{
public:
	CScene(void);
	virtual ~CScene(void);

	bool Update( float deltaTime );
	void Render();

private:
	Position	m_CameraPosition;
	CPC			m_PlayerCharacter;
	CZone *		m_Zone;
	CCastUI *	m_CastingUI;
};