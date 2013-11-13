#include "stdafx.h"
#include "Monster.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "AnimationInfo.h"

#include <cmath>

#define WALK_SPEED	64
#define SIGHT		256 // ���� �þ�

CMonster::CMonster( std::wstring monsterId )
	:	m_MonsterId( monsterId )
{
}


CMonster::~CMonster(void)
{
	for ( auto animation : m_Animation )
		SafeDelete( animation );
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
		m_Animation.push_back( animation );
		SafeRelease( animationInfo );
	}

	return true;
}

bool CMonster::Update( float deltaTime, Position & playerPosition )
{
	CGameObject::Update( deltaTime, playerPosition );

	//  �÷��̾���� �Ÿ� üũ
	float distance_PC_X = playerPosition.x - m_Position.x;
	float distance_PC_Y = playerPosition.y - m_Position.y;
	float distance_PC = sqrt( pow( distance_PC_X, 2 ) + pow( distance_PC_Y, 2 ) );

	//  �þ߳��� ������ �÷��̾� �ѱ�
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

	return true;
}

CAnimation * CMonster::GetAnimation() const
{

	// agebreak : �ִϸ��̼� ����Ʈ�� ������� ������ �� �ִٰ� �����ϴ� �ڵ�� ���� ����
	// Ű���� ���� Map�� ���·� ����°��� �� ���� 
	CAnimation * animation = m_Animation[3];

	switch( m_Position.direction )
	{
	case LEFT:
		animation = m_Animation[0];
		break;

	case RIGHT:
		animation = m_Animation[1];
		break;

	case UP:
		animation = m_Animation[2];
		break;

	case DOWN:
		animation = m_Animation[3];
		break;
	}

	if ( m_Status == WALK )
		animation->SetSpeed( 8 );
	else if ( m_Status == STAND )
		animation->SetSpeed( 0 );

	return animation;
}
