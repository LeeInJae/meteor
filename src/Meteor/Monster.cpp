#include "stdafx.h"
#include "Monster.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "AnimationInfo.h"

#include <cmath>
#include <iostream>

#define SKELETON_MAGE_WALK_SPEED	64
#define SKELETON_MAGE_SIGHT			256
#define SKELETON_MAGE_ATTACK_RANGE	64

const static float PI = 3.14159265359f;

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
	Position diff = playerPosition - m_Position;
	float distance = sqrt( pow( diff.x, 2 ) + pow( diff.y, 2 ) );

	//  시야내에 있을시 플레이어 쫓기
	if( distance <= SKELETON_MAGE_SIGHT && distance > SKELETON_MAGE_ATTACK_RANGE) {
		m_Status = CHARACTER_WALK;

		float slope = atan2( -diff.y, diff.x );
		int slopeLevel = static_cast<int>( ( slope + PI ) * 8.0f / PI );	// 0 ~ 16 level
		//switch ( slopeLevel )
		//{
		//case 1:
		//case 2:
		//	m_Direction = DOWN_LEFT;
		//	break;
		//case 3:
		//case 4:
		//	m_Direction = DOWN;
		//	break;
		//case 5:
		//case 6:
		//	m_Direction = DOWN_RIGHT;
		//	break;
		//case 7:
		//case 8:
		//	m_Direction = RIGHT;
		//	break;
		//case 9:
		//case 10:
		//	m_Direction = UP_RIGHT;
		//	break;
		//case 11:
		//case 12:
		//	m_Direction = UP;
		//	break;
		//case 13:
		//case 14:
		//	m_Direction = UP_LEFT;
		//	break;
		//default:	// 0, 15, 16
		//	m_Direction = LEFT;
		//	break;
		//}

		switch ( slopeLevel )
		{
		case 2:
		case 3:
		case 4:
		case 5:
			m_Direction = DOWN;
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			m_Direction = RIGHT;
			break;
		case 10:
		case 11:
		case 12:
		case 13:
			m_Direction = UP;
			break;
		default:	// 0, 1, 14, 15, 16
			m_Direction = LEFT;
			break;
		}

		Walk( m_Direction, deltaTime * SKELETON_MAGE_WALK_SPEED );
	}
	else if( m_Status == CHARACTER_STAND && distance <= SKELETON_MAGE_ATTACK_RANGE ) {
		m_Status = CHARACTER_STAND;
	}
	else if( m_Status == CHARACTER_WALK && distance <= SKELETON_MAGE_ATTACK_RANGE - 10 ){
		m_Status = CHARACTER_STAND;
	}
	else {
		m_Status = CHARACTER_STAND;
	}

	return false;
}

CAnimation * CMonster::GetAnimation() const
{
	std::wstring animationId;
	switch( m_Direction )
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

	if ( m_Status == CHARACTER_WALK )
		animation->SetSpeed( 8 );
	else if ( m_Status == CHARACTER_STAND )
		animation->SetSpeed( 0 );

	return animation;
}
