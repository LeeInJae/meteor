#include "stdafx.h"
#include "Monster.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "AnimationInfo.h"

#include <cmath>

#define WALK_SPEED	64
#define SIGHT		256 // 몬스터 시야

CMonster::CMonster( std::wstring monsterId )
	:	m_MonsterId( monsterId )
{
}


CMonster::~CMonster(void)
{
	for ( auto animation : m_Animation )
		SafeDelete( animation.second );
	m_Animation.clear();
}

bool CMonster::LoadAnimation()
{
	std::wstring animationIdList[] = { 
		m_MonsterId + L"_walk_left", 
		m_MonsterId + L"_walk_right", 
		m_MonsterId + L"_walk_up", 
		m_MonsterId + L"_walk_down" 
	};

	for each ( std::wstring animationId in animationIdList )
	{
		CAnimationInfo * animationInfo = CResourceManager::GetInstance().GetAnimationInfo( animationId );
		CAnimation * animation = animationInfo->CreateAnimation();
		//m_Animation.push_back( animation );
		m_Animation[animationId] = animation;
		SafeRelease( animationInfo );
	}

	return true;
}

bool CMonster::Update( float deltaTime, Position & playerPosition )
{
	CGameObject::Update( deltaTime, playerPosition );

	//  플레이어와의 거리 체크
	float distance_PC_X = playerPosition.x - m_Position.x;
	float distance_PC_Y = playerPosition.y - m_Position.y;
	float distance_PC = sqrt( pow( distance_PC_X, 2 ) + pow( distance_PC_Y, 2 ) );

	//  시야내에 있을시 플레이어 쫓기
	if( distance_PC < SIGHT ){
		m_Status = WALK;
		
		if( abs( distance_PC_X ) > abs( distance_PC_Y ) ){
			if( distance_PC_X < 0 )	m_Position.direction = LEFT;
			else					m_Position.direction = RIGHT;
		}
		else{
			if( distance_PC_Y < 0 )	m_Position.direction = UP;
			else					m_Position.direction = DOWN;
		}

		float speed_X = ( distance_PC_X / distance_PC ) * WALK_SPEED;
		float speed_Y = ( distance_PC_Y / distance_PC ) * WALK_SPEED;
		Move( speed_X * deltaTime, speed_Y * deltaTime );
	}
	else{
		m_Status = STAND;
	}

	return true;
}

CAnimation * CMonster::GetAnimation() const
{
	std::wstring animationId;
	switch( m_Position.direction )
	{
	case LEFT:
		animationId = L"skeleton_mage_walk_left";
		break;

	case RIGHT:
		animationId = L"skeleton_mage_walk_right";
		break;

	case UP:
		animationId = L"skeleton_mage_walk_up";
		break;

	case DOWN:
		animationId = L"skeleton_mage_walk_down";
		break;
	}
	CAnimation * animation = m_Animation.find(animationId)->second;

	if ( m_Status == WALK )
		animation->SetSpeed( 8 );
	else if ( m_Status == STAND )
		animation->SetSpeed( 0 );

	return animation;
}
