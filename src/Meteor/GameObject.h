#pragma once
class CGameObject
{
public:
	CGameObject(void);
	virtual ~CGameObject(void);

	bool render();
	bool update();
};

