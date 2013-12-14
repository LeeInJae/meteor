#include "stdafx.h"
#include "BasicAttack.h"
#include "PC.h"


CBasicAttack::CBasicAttack()
{
	m_SkillName = L"effect_slash";
	m_Damage = 1.0f;
	m_Duration = 0.7f;
	m_Boundary.SetRadius( 60.0f );
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
	animation->Play( 0, false );

	Direction m_Direction = target->GetDirection();

	switch( m_Direction )
	{
		case UP:
			m_Boundary.SetCenter( 0.0f, -50.0f );
			break;
		case UP_RIGHT:
			m_Boundary.SetCenter( 31.0f, -31.0f );
			break;
		case RIGHT:
			m_Boundary.SetCenter( 50.0f, 0.0f );
			break;
		case DOWN_RIGHT:
			m_Boundary.SetCenter( 31.0f, 31.0f );
			break;
		case DOWN:
			m_Boundary.SetCenter( 0.0f, 50.0f );
			break;
		case DOWN_LEFT:
			m_Boundary.SetCenter( -31.0f, 31.0f );
			break;
		case LEFT:
			m_Boundary.SetCenter( -50.0f, 0.0f );
			break;
		case UP_LEFT:
			m_Boundary.SetCenter( -31.0f, -31.0f );
			break;
	}

	m_EventType = EVENT_HIT;

	IEventSubject<CGameObject> * eventSubject = target->GetSubject();
	if( eventSubject )
		eventSubject->SendEvent( this );

}

bool CBasicAttack::HitCheck( CGameObject * target )
{
	return ( typeid( *target ) != typeid( *m_Target ) );
}
