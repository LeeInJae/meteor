#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject(void)
{
	m_Position.mode = BASE_CENTER;
	m_Position.direction = DOWN;
}

CGameObject::~CGameObject(void)
{
}

bool CGameObject::Update( float deltaTime, Position & playerPosition )
{
	CAnimation * animation = GetAnimation();
	assert( animation );

	if ( animation )
		animation->Update( deltaTime );

	return true;
}

bool CGameObject::Render( Position & cameraPosition )
{
	CAnimation * animation = GetAnimation();
	assert( animation );

	if ( animation )
	{
		animation->SetPosition( m_Position, cameraPosition );
		animation->Render();
	}

	return true;
}


bool CGameObject::Move( float x, float y )
{
	m_Position.x += x;
	m_Position.y += y;

	return true;
}
