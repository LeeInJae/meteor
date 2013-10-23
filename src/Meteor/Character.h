#pragma once
#include "gameobject.h"
enum CharacterStatus {
	DEAD,
	STAND,
	WALK,
	ATTACK,
	CASTING,
	DEFENCE,
	AVOID,
};
class CCharacter :
	public CGameObject
{
public:
	CCharacter(void);
	virtual ~CCharacter(void);

protected:
	int m_HP;
};

