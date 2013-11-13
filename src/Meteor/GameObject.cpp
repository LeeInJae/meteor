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
	// agebreak : 애니메이션 객체가 없을 경우의 방어처리가 되어 있지 않음. 
	CAnimation * animation = GetAnimation();
	assert( animation );

	if ( animation )
		animation->Update( deltaTime );

	return true;
}

bool CGameObject::Render()
{
	// agebreak : 애니메이션 객체가 없을 경우의 방어처리가 되어 있지 않음. 
	CAnimation * animation = GetAnimation();
	assert( animation );

	if ( animation )
		animation->Render();

	return true;
}


bool CGameObject::Move(float x, float y)
{
	m_Position.x += x;
	m_Position.y += y;

	return true;
}
