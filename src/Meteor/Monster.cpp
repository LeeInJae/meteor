#include "stdafx.h"
#include "Monster.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "AnimationInfo.h"
#include "MonsterAttack.h"
#include "Zone.h"
#include "PC.h"

#include <cmath>
#include <iostream>

#define SKELETON_MAGE_WALK_SPEED	64
#define SKELETON_MAGE_SIGHT			512
#define SKELETON_MAGE_ATTACK_RANGE	64

CMonster::CMonster( ResourceId monsterId )
	: m_MonsterId( monsterId )
{
	m_BasicAttack = new CMonsterAttack();

	m_Speed			= SKELETON_MAGE_WALK_SPEED;
	m_BackSpeed		= SKELETON_MAGE_WALK_SPEED * 25;

	m_Type			= MONSTER;
}


CMonster::~CMonster(void)
{
	for ( auto animation : m_Animation )
		SafeDelete( animation.second );
}

bool CMonster::LoadAnimation()
{
	ResourceId actionIdList[] = {
		L"_walk",
		L"_attack",
		L"_stiff",
		L"_dead",
	};

	ResourceId directionIdList[] = {
		L"_left",
		L"_right",
		L"_up",
		L"_up_left",
		L"_up_right",
		L"_down",
		L"_down_left",
		L"_down_right",
	};

	for each ( ResourceId actionId in actionIdList )
	{
		for each ( ResourceId directionId in directionIdList )
		{
			ResourceId animationId = m_MonsterId + actionId + directionId;
			CAnimationInfo * animationInfo = CResourceManager::GetInstance().GetAnimationInfo( animationId );
			if ( animationInfo )
			{
				CAnimation * animation = animationInfo->CreateAnimation();
				m_Animation[animationId] = animation;
			}
			SafeRelease( animationInfo );
		}
	}

	return true;
}


void CMonster::Resurrect()
{
	SetHp( 2.0f );
	SetStatus( CHARACTER_STAND );
	m_Zone->SetRandomPosition( this );
}


bool CMonster::Action()
{
	if( m_ActionTime > 0.0f )
		return false;

	SetStatus( CHARACTER_ATTACK );
	GetAnimation()->Play( 0, false );
		
	m_Skill			= m_BasicAttack;
	m_ActionTime	= m_Skill->GetDuration();
	m_Skill->ApplySkill( this );

	return true;
}

bool CMonster::Update( float deltaTime )
{
	if( IsDead() )
	{
		if( m_ActionTime > 0.0f )
			return CCharacter::Update( deltaTime );

		Resurrect();
	}

	Position playerPosition = m_Zone->GetPlayer()->GetPosition();

	//  �÷��̾���� �Ÿ� üũ
	float distance = GetDistance( m_Position, playerPosition );

	//  �þ߳��� ������ �÷��̾� �ѱ�
	if( distance < SKELETON_MAGE_ATTACK_RANGE )
	{
		Action();
	}
	else if( distance <= SKELETON_MAGE_SIGHT && distance > SKELETON_MAGE_ATTACK_RANGE) {
		SetStatus( CHARACTER_WALK );

		Vector diff = playerPosition - m_Position;
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
		animationId = L"skeleton_mage_attack";
		break;
	case CHARACTER_STIFF:
		animationId = L"skeleton_mage_stiff";
		break;
	case CHARACTER_DEAD:
		animationId = L"skeleton_mage_dead";
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


void CMonster::EventHandler( CGameObject * event )
{
	if( event->GetEventType() == EVENT_DEAD )
	{
		// ���� ���� ��ġ
		CMonster * monster = new CMonster( L"skeleton_mage" );
		monster->LoadAnimation();
		monster->SetDirection( RIGHT );
		monster->SetHp( 2.0f );
		monster->SetMaxHp( 2.0f );

		m_Zone->SetRandomPosition( monster );
		m_Zone->AddObject( monster );
	}
	else
		CCharacter::EventHandler( event );
}
