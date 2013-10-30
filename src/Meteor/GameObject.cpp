#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject(void)
	: m_Direction(DOWN)
{
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