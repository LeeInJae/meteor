#include "stdafx.h"
#include "PC.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "AnimationInfo.h"
#include "BasicAttack.h"
#include "FlameSlash.h"

#define WALK_SPEED 192

CPC::CPC(void)
{
	CBasicAttack * basicAttack = new CBasicAttack();
	basicAttack->LoadAnimation();
	m_BasicAttack = basicAttack;

	m_SkillTable["RedGreen"] = new CFlameSlash();
	m_SkillTable["RedGreen"]->LoadAnimation();

	m_Speed = WALK_SPEED;
}

CPC::~CPC(void)
{
	for ( auto animation : m_Animation )
		SafeDelete( animation.second );

	for ( auto skill : m_SkillTable )
		SafeDelete( skill.second );

	SafeDelete( m_BasicAttack );
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
		L"character_slash_down_right",
		L"character_stiff_left",
		L"character_stiff_right", 
		L"character_stiff_up", 
		L"character_stiff_up_left", 
		L"character_stiff_up_right", 
		L"character_stiff_down", 
		L"character_stiff_down_left", 
		L"character_stiff_down_right",
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
	if ( m_Casting.size() < 6 )
		m_Casting.push_back( id );
	return true;
}

bool CPC::Action()
{
	if( m_ActionTime > 0.0f )
		return false;

	if( m_Casting.empty() )
	{
		SetStatus( CHARACTER_ATTACK );
		GetAnimation()->Play( 0, false );
		
		m_Skill = m_BasicAttack;
		m_ActionTime = m_Skill->GetDuration();
		m_Skill->ApplySkill( this );

		return true;
	}

	std::string castingGems;
	for ( auto cast : m_Casting )
	{
		castingGems += cast;
	}
	
	m_Casting.clear();

	if ( m_SkillTable[castingGems] == nullptr )
		return false;

	SetStatus( CHARACTER_ATTACK );
	GetAnimation()->Play( 0, false );

	m_Skill			= m_SkillTable[castingGems];
	m_ActionTime	= m_Skill->GetDuration();
	m_Skill->SetPosition( m_Position.x, m_Position.y );
	m_Skill->SetSubject( m_EventSubject );
	m_Skill->ApplySkill( this );
		
	return true;
}
