#include "stdafx.h"
#include "PC.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "AnimationInfo.h"
#include "BasicAttack.h"
#include "FlameSlash.h"

#define WALK_SPEED 256

CPC::CPC(void)
{
	CBasicAttack * basicAttack = new CBasicAttack();
	basicAttack->LoadAnimation();
	m_BasicAttack = basicAttack;

	m_SkillTable["RedGreen"] = new CFlameSlash();
	m_SkillTable["RedGreen"]->LoadAnimation();

	m_Speed		= WALK_SPEED;
	m_BackSpeed	= WALK_SPEED * 2.0f;

	m_Type		= PLAYER;
}

CPC::~CPC(void)
{
	for ( auto animation : m_Animation )
		SafeDelete( animation.second );

	for ( auto skill : m_SkillTable )
		SafeDelete( skill.second );
}

bool CPC::LoadAnimation()
{
	ResourceId actionIdList[] = {
		L"_walk",
		L"_slash",
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
			ResourceId animationId = L"character" + actionId + directionId;
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


CAnimation * CPC::GetAnimation() const
{
	int speed = 0;
	ResourceId animationId;

	switch ( GetStatus() )
	{
	case CHARACTER_WALK:
		animationId = L"character_walk";
		break;
	case CHARACTER_STAND:
		animationId = L"character_walk";
		break;
	case CHARACTER_ATTACK:
		animationId = L"character_slash";
		break;
	case CHARACTER_STIFF:
		animationId = L"character_stiff";
		break;
	case CHARACTER_DEAD:
		animationId = L"character_dead";
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

bool CPC::Cast( std::string id )
{
	if ( IsAlive() && m_Casting.size() < 6 )
		m_Casting.push_back( id );
	return true;
}

bool CPC::Action()
{
	if( m_ActionTime > 0.0f || IsDead() )
		return false;

	if( m_Casting.empty() )
	{
		SetStatus( CHARACTER_ATTACK );
		GetAnimation()->Play( 0, false );
		
		m_Skill			= m_BasicAttack;
		m_ActionTime	= m_Skill->GetDuration();
		m_Skill->ApplySkill( this );

		return true;
	}

	std::string castingGems;
	for ( auto cast : m_Casting )
	{
		if( m_CoolTime[cast] > 0 )
		{
			m_Casting.clear();
			return false;
		}
		else
			castingGems += cast;
	}
	
	if ( m_SkillTable[castingGems] == nullptr )
	{
		m_Casting.clear();
		return false;
	}

	SetStatus( CHARACTER_ATTACK );
	GetAnimation()->Play( 0, false );

	m_Skill			= m_SkillTable[castingGems];
	m_ActionTime	= m_Skill->GetDuration();
	m_Skill->SetPosition( m_Position.x, m_Position.y );
	m_Skill->SetSubject( m_EventSubject );
	m_Skill->ApplySkill( this );
	
	for ( auto cast : m_Casting )
	{
		m_CoolTime[cast] += 2.0f;
	}
	m_Casting.clear();

	return true;
}

bool CPC::Update( float deltaTime )
{
	for ( auto gem : m_CoolTime )
	{
		if ( gem.second > 0.0f )
			m_CoolTime[gem.first] -= deltaTime;
		else
			m_CoolTime[gem.first] = 0.0f;
	}
	return CCharacter::Update( deltaTime );
}


void CPC::EventHandler( CGameObject * event )
{
	if( event->GetEventType() == EVENT_DEAD )
	{
		m_Casting.clear();
	}
	else
		CCharacter::EventHandler( event );
}
