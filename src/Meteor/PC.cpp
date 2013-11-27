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
		L"character_walk_down_right",
		L"character_slash_left", 
		L"character_slash_right", 
		L"character_slash_up", 
		L"character_slash_up_left", 
		L"character_slash_up_right", 
		L"character_slash_down", 
		L"character_slash_down_left", 
		L"character_slash_down_right"
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

	if ( m_ActionTime > 0.0f )
		m_ActionTime -= deltaTime;

	if ( m_Status == CHARACTER_WALK )
		Walk( m_Direction, WALK_SPEED * deltaTime );
	
	return true;
}

CAnimation * CPC::GetAnimation() const
{
	int speed = 0;
	ResourceId animationId;

	switch ( m_Status )
	{
	case CHARACTER_WALK:
		speed = 8;
		animationId = L"character_walk";
		break;
	case CHARACTER_STAND:
		speed = 0;
		animationId = L"character_walk";
		break;
	case CHARACTER_ATTACK:
		speed = 8;
		animationId = L"character_slash";
		break;
	}

	switch( m_Direction )
	{
	case LEFT:
		animationId += L"_left";
		break;
	case RIGHT:
		animationId += L"_right";
		break;
	case UP:
		animationId += L"_up";
		break;
	case UP_LEFT:
		animationId += L"_up_left";
		break;
	case UP_RIGHT:
		animationId += L"_up_right";
		break;
	case DOWN:
		animationId += L"_down";
		break;
	case DOWN_LEFT:
		animationId += L"_down_left";
		break;
	case DOWN_RIGHT:
		animationId += L"_down_right";
		break;
	}
	CAnimation * animation = m_Animation.find(animationId)->second;

	animation->SetSpeed( speed );
	return animation;
}