#include "stdafx.h"
#include "PC.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "AnimationInfo.h"

#define WALK_SPEED 192

CPC::CPC(void)
{
}

CPC::~CPC(void)
{
	for ( auto animation : m_Animation )
		SafeDelete( animation.second );
	m_Animation.clear();
}

bool CPC::LoadAnimation()
{
	ResourceId animationIdList[] = { 
		L"character_walk_left", 
		L"character_walk_right", 
		L"character_walk_up", 
		L"character_walk_up_left", 
		L"character_walk_up_right", 
		L"character_walk_down", 
		L"character_walk_down_left", 
		L"character_walk_down_right"
	};

	for each ( ResourceId animationId in animationIdList )
	{
		CAnimationInfo * animationInfo = CResourceManager::GetInstance().GetAnimationInfo( animationId );
		CAnimation * animation = animationInfo->CreateAnimation();
		m_Animation[animationId] = animation;
		SafeRelease( animationInfo );
	}

	return true;
}

bool CPC::Update( float deltaTime )
{
	CGameObject::Update( deltaTime, m_Position );

	if ( m_Status == CHARACTER_WALK )
		Walk( m_Direction, WALK_SPEED * deltaTime );

	return true;
}

CAnimation * CPC::GetAnimation() const
{
	ResourceId animationId;
	switch( m_Direction )
	{
	case LEFT:
		animationId = L"character_walk_left";
		break;

	case RIGHT:
		animationId = L"character_walk_right";
		break;

	case UP:
		animationId = L"character_walk_up";
		break;

	case UP_LEFT:
		animationId = L"character_walk_up_left";
		break;

	case UP_RIGHT:
		animationId = L"character_walk_up_right";
		break;

	case DOWN:
		animationId = L"character_walk_down";
		break;

	case DOWN_LEFT:
		animationId = L"character_walk_down_left";
		break;

	case DOWN_RIGHT:
		animationId = L"character_walk_down_right";
		break;
	}
	CAnimation * animation = m_Animation.find(animationId)->second;

	switch ( m_Status )
	{
	case CHARACTER_WALK:
		animation->SetSpeed( 8 );
		break;
	case CHARACTER_STAND:
		animation->SetSpeed( 0 );
		break;
	case CHARACTER_ATTACK:
		break;
	}

	return animation;
}


void CPC::Action()
{
}