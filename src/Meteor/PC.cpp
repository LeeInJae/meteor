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
	std::wstring animationIdList[] = { L"character_walk_left", L"character_walk_right", L"character_walk_up", L"character_walk_down" };

	for each ( std::wstring animationId in animationIdList )
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
	std::wstring animationId;
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

	case DOWN:
		animationId = L"character_walk_down";
		break;
	}
	CAnimation * animation = m_Animation.find(animationId)->second;

	if ( m_Status == CHARACTER_WALK )
		animation->SetSpeed( 8 );
	else if ( m_Status == CHARACTER_STAND )
		animation->SetSpeed( 0 );

	return animation;
}
