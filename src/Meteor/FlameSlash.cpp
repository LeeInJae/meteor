#include "stdafx.h"
#include "FlameSlash.h"

#define MOVE_SPEED 512

CFlameSlash::CFlameSlash(void)
{
	m_SkillName = L"effect_flame_slash";
	m_Damage = 2.0f;
	m_Duration = 0.7f;
}


CFlameSlash::~CFlameSlash(void)
{
}

bool CFlameSlash::LoadAnimation()
{
	CAnimationInfo * animationInfo = CResourceManager::GetInstance().GetAnimationInfo( m_SkillName );
	CAnimation * animation = animationInfo->CreateAnimation();
	animation->SetSpeed(8);
	m_Animation[ m_SkillName ] = animation;
	SafeRelease( animationInfo );

	return true;
}

CAnimation * CFlameSlash::GetAnimation() const
{
	CAnimation * animation = m_Animation.find(m_SkillName)->second;

	return animation;
}

bool CFlameSlash::Update( float deltaTime )
{
	Move( m_Direction, MOVE_SPEED * deltaTime );
	return CGameObject::Update( deltaTime );
}

void CFlameSlash::ApplySkill( CGameObject * target )
{
	m_Target = target;
	m_Direction = target->GetDirection();

	CAnimation * animation = GetAnimation();
	animation->SetRotation( -225.0f + 45.0f * m_Direction );
	animation->Play( 0, false );
}
