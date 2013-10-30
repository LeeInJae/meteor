
#pragma once
#include "PC.h"

class CScene
{
public:
	CScene(void);
	virtual ~CScene(void);

	void Update( float deltaTime );
	void Render();

private:
	CPC m_PlayerCharacter;
};