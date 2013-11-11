#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject(void)
{
	m_Position.direction = DOWN;
}

CGameObject::~CGameObject(void)
{
}

bool CGameObject::Update( float deltaTime )
{
	CAnimation * animation = GetAnimation();
	animation->Update( deltaTime );

	return true;
}

bool CGameObject::Render()
{
	CAnimation * animation = GetAnimation();
	animation->Render();

	return true;
}


bool CGameObject::Move(float x, float y)
{
	m_Position.x += x;
	m_Position.y += y;

	return true;
}
