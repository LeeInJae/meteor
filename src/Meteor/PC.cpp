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
}

CPC::~CPC(void)
{
	for ( auto animation : m_Animation )
		SafeDelete( animation.second );
	m_Animation.clear();

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
	CCharacter::Update( deltaTime );

	if ( m_Status == CHARACTER_WALK )
		Walk( m_Direction, WALK_SPEED * deltaTime );
	else if ( m_Status == CHARACTER_ATTACK )
		Walk( m_Direction, WALK_SPEED * 0.5f * deltaTime );
	
	return true;
}


CAnimation * CPC::GetAnimation() const
{
	int speed = 0;
	ResourceId animationId;

	switch ( m_Status )
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

	switch ( m_Status )
	{
	case CHARACTER_WALK:
		animation->Play( 8 );
		break;
	case CHARACTER_STAND:
		animation->Stop( true );
		break;
	case CHARACTER_ATTACK:
		animation->Play( 10, false );
		break;
	}

	return animation;
}

//bool CPC::Cast( int id )
//{
//	if ( m_Casting.size() < 6 )
//		m_Casting.push_back( id );
//
//	return true;
//}

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

/*	SHORT cast_table[][6] =
	{
		{ 1, 2, 3, -1, -1, -1 },	// 0: Init Status
		{ 5, -1, -1, -1, -1, -1 },	// 1: R
		{ -1, -1, -1, -1, -1, -1 },	// 2: B
		{ -1, -1, -1, -1, -1, -1 },	// 3: G
		{ -1, -1, -1, -1, -1, -1 },	// 4: Y
		{ -1, -1, -1, -1, -1, -1 },	// 5: RB
	};

	SHORT skill_table[] =
	{
		-1,
		-1, // 1: ID_SKILL_FIRE_BOLT,
		-1,	// 2: ID_SKILL_WIND_STORM,
		-1,	// 3: ID_SKILL_POISON_PLANT
		-1,	// 4: ID_SKILL_???
		5,	// 5: ID_SKILL_FIRE_STORM
	};
*/

	//std::map< std::string, std::wstring > skill_table;
	//skill_table["Red"] = L"skill_fire_bolt";
	//skill_table["RedGreen"] = L"skill_flame_slash";
	//skill_table["RedRedGreen"] = L"skill_fire_storm";

	std::map< std::string, CSkill * > skill_table;
	skill_table["RedGreen"] = new CFlameSlash();
	skill_table["RedGreen"]->LoadAnimation();

/*
	if ( m_Casting.size() == 0 )
		return CCharacter::Action();

	SHORT index = 0;
	for ( auto cast : m_Casting )
		if ( ( index = cast_table[ index ][ cast ] ) == -1 )
			break;
*/
	if( m_Casting.empty() ){
		m_Status = CHARACTER_ATTACK;
		
		m_Skill = m_BasicAttack;
		m_ActionTime = m_Skill->GetDuration();
		m_Skill->ApplySkill( this );

		GetAnimation()->Stop( true );

		return true;
	}

	std::string castingGems;
	for ( auto cast : m_Casting ){
		castingGems += cast;
	}
	
	m_Casting.clear();

	//if ( skill_table[castingGems].empty() )
	//	wprintf_s( L"SKILL : There is no such a skill.\n");
	//else{
	//	wprintf_s( L"SKILL : %s\n", skill_table[castingGems].c_str() );
	//}

	if ( skill_table[castingGems] == nullptr )
		return false;
	else{
		m_Status = CHARACTER_ATTACK;

		m_Skill = skill_table[castingGems];
		m_ActionTime = m_Skill->GetDuration();
		m_Skill->SetPosition( m_Position.x, m_Position.y );
		m_Skill->ApplySkill( this );
		
		GetAnimation()->Stop( true );

		return true;
	}

	//if ( index == -1 )
	//	return false;

	// TODO: Implement Skill

	return true;


}
