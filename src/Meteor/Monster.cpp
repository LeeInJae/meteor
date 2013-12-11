#include "stdafx.h"
#include "Monster.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "AnimationInfo.h"

#include <cmath>
#include <iostream>

#define SKELETON_MAGE_WALK_SPEED	64
#define SKELETON_MAGE_SIGHT			512
#define SKELETON_MAGE_ATTACK_RANGE	64

CMonster::CMonster( ResourceId monsterId )
	: m_MonsterId( monsterId )
{
	m_Speed = SKELETON_MAGE_WALK_SPEED;
}


CMonster::~CMonster(void)
{
	for ( auto animation : m_Animation )
		SafeDelete( animation.second );
	m_Animation.clear();
}

bool CMonster::LoadAnimation()
{
	ResourceId animationIdList[] = { 
		m_MonsterId + L"_walk_left", 
		m_MonsterId + L"_walk_right", 
		m_MonsterId + L"_walk_up", 
		m_MonsterId + L"_walk_up_left", 
		m_MonsterId + L"_walk_up_right", 
		m_MonsterId + L"_walk_down", 
		m_MonsterId + L"_walk_down_left", 
		m_MonsterId + L"_walk_down_right", 
		m_MonsterId + L"_stiff_left", 
		m_MonsterId + L"_stiff_right", 
		m_MonsterId + L"_stiff_up", 
		m_MonsterId + L"_stiff_up_left", 
		m_MonsterId + L"_stiff_up_right", 
		m_MonsterId + L"_stiff_down", 
		m_MonsterId + L"_stiff_down_left", 
		m_MonsterId + L"_stiff_down_right", 
	};

	for each ( ResourceId animationId in animationIdList )
	{
		CAnimationInfo * animationInfo = CResourceManager::GetInstance().GetAnimationInfo( animationId );
		CAnimation * animation = animationInfo->CreateAnimation();
		//m_Animation.push_back( animation );
		m_Animation[animationId] = animation;
		SafeRelease( animationInfo );
	}

	return true;
}

bool CMonster::Update( float deltaTime )
{
	Position playerPosition = CSceneManager::GetInstance().GetCurrentScene()->GetPlayer().GetPosition();

	//  플레이어와의 거리 체크
	Vector diff = playerPosition - m_Position;
	float distance = sqrt( pow( diff.x, 2 ) + pow( diff.y, 2 ) );

	//  시야내에 있을시 플레이어 쫓기
	if( distance <= SKELETON_MAGE_SIGHT && distance > SKELETON_MAGE_ATTACK_RANGE) {
		SetStatus( CHARACTER_WALK );

		float slope = atan2( -diff.y, diff.x );
		SetDirection( ::GetDirection<float>( m_Position.x, m_Position.y, playerPosition.x, playerPosition.y ) );

		//Move( deltaTime * SKELETON_MAGE_WALK_SPEED * cos( slope ), -deltaTime * SKELETON_MAGE_WALK_SPEED * sin( slope ) );
	}
	else
		SetStatus( CHARACTER_STAND );

	return CCharacter::Update( deltaTime );
}

CAnimation * CMonster::GetAnimation() const
{
	ResourceId animationId;

	switch ( GetStatus() )
	{
	case CHARACTER_WALK:
		animationId = L"skeleton_mage_walk";
		break;
	case CHARACTER_STAND:
		animationId = L"skeleton_mage_walk";
		break;
	case CHARACTER_ATTACK:
		animationId = L"skeleton_mage_slash";
		break;
	case CHARACTER_STIFF:
		animationId = L"skeleton_mage_stiff";
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

	return animation;
}
