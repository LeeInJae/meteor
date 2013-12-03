#include "stdafx.h"
#include "BasicAttack.h"


CBasicAttack::CBasicAttack()
{
	m_SkillName = L"effect_slash";
	m_Duration = 0.7f;
}


CBasicAttack::~CBasicAttack(void)
{
}

bool CBasicAttack::Update( float deltaTime )
{
	m_Position = m_Target->GetPosition();
	CAnimation * animation = GetAnimation();
	assert( animation );

	if ( animation )
		animation->Update( deltaTime );

	return true;
}

void CBasicAttack::ApplySkill( CGameObject * target )
{
	m_Target = target;
	CAnimation * animation = GetAnimation();
	animation->Stop( true );
	animation->Play( 10, false );

	//Direction m_Direction = target->GetDirection();

}
