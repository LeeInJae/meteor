#include "stdafx.h"
#include "Character.h"
#include "HpUI.h"

const static float SQRT2_2 = 0.70710678118f;

CCharacter::CCharacter(void)
	: m_Hp(1.0f)
	, m_MaxHp(1.0f)
	, m_Speed(0.0f)
	, m_BackSpeed(0.0f)
	, m_ActionTime(0.0f)
	, m_BasicAttack(nullptr)
	, m_Skill(nullptr)
	, m_Status(CHARACTER_STAND)
{
	m_HpUI = new CHpUI( this );
}

CCharacter::~CCharacter(void)
{
	SafeDelete( m_HpUI );
	SafeDelete( m_BasicAttack );
}


bool CCharacter::Update( float deltaTime )
{
	if ( m_ActionTime > 0.0f )
		m_ActionTime -= deltaTime;
	else
		m_Skill = nullptr;

	if( IsDead() )
		return CGameObject::Update( deltaTime );

	if ( m_Skill )
	{
		m_Skill->Update( deltaTime );
	}

	m_HpUI->Update( deltaTime );

	if ( m_Status == CHARACTER_WALK )
		Move( m_Direction, m_Speed * deltaTime );
	else if ( m_Status == CHARACTER_ATTACK )
		Move( m_Direction, m_Speed * 0.5f * deltaTime );
	else if ( m_Status == CHARACTER_STIFF )
		Move( m_Direction, -m_BackSpeed * deltaTime );
	
	return CGameObject::Update( deltaTime );
}


void CCharacter::Render( const Position & cameraPosition )
{
	CGameObject::Render( cameraPosition );

	if ( IsDead() )
		return;

	if ( m_Skill )
		m_Skill->Render( cameraPosition );

	m_HpUI->SetPosition( cameraPosition );
	m_HpUI->Render();
}


bool CCharacter::HitCheck( CSkill * skill )
{
	return ( GetBoundary().isIntersected( skill->GetBoundary() )
		&& skill->HitCheck( this ) );
}


bool CCharacter::Move( float x, float y )
{
	if ( CGameObject::Move( x, y ) )
		return true;

	SetStatus( CHARACTER_STAND );
	return false;
}

bool CCharacter::Move( Direction direction, float distance )
{
	if ( CGameObject::Move( direction, distance ) )
		return true;

	SetStatus( CHARACTER_STAND );
	return false;
}

void CCharacter::SetStatus( CharacterStatus status )
{
	if ( m_Status == status )
		return;

	if ( IsDead() && status != CHARACTER_DEAD )
		return;

	if ( IsAlive() && m_ActionTime > 0.0f )
	{
		if ( status != CHARACTER_STIFF || m_Status != CHARACTER_ATTACK )
			return;
	}

	m_Status = status;

	ResetAnimation();
}


void CCharacter::SetDirection( Direction direction )
{
	if ( m_Direction == direction )
		return;

	if ( IsDead() || m_Status == CHARACTER_DEAD )
		return;

	if ( IsAlive() && m_ActionTime > 0.0f )
		return;
	m_Direction = direction;

	ResetAnimation();
}


void CCharacter::ResetAnimation()
{
	switch ( m_Status )
	{
	case CHARACTER_STAND:
		GetAnimation()->Stop( 0 );
		break;
	case CHARACTER_WALK:
		GetAnimation()->Play( 0, true );
		break;
	case CHARACTER_ATTACK:
		GetAnimation()->Play( 0, false );
		break;
	case CHARACTER_STIFF:
		GetAnimation()->Stop( 0 );
		break;
	case CHARACTER_DEAD:
		GetAnimation()->Play( 0, false );
		break;
	}
}


void CCharacter::EventHandler( CGameObject * event )
{
	if ( ! event ) return;
	if ( this == event ) return;
	if ( IsDead() ) return;

	CGameObject::EventHandler( event );

	if ( ( event->GetEventType() == EVENT_HIT ) )
	{
		CSkill * skill = static_cast<CSkill *>(event);

		if( HitCheck( skill ) )
		{
			m_Hp -= skill->GetDamage();
			if ( m_Hp < 1e-6f )
			{
				m_Hp = 0.0f;
				switch ( m_Direction )
				{
				case UP_LEFT:
				case DOWN_LEFT:
				case DOWN:
					m_Direction = LEFT;
					break;
				case UP_RIGHT:
				case DOWN_RIGHT:
				case UP:
					m_Direction = RIGHT;
					break;
				default:
					break;
				}

				SetEventType( EVENT_DEAD );
				EventHandler( this );
 				SetStatus( CHARACTER_DEAD );
				m_ActionTime = 5.0f;

			}
			else
			{
				SetStatus( CHARACTER_STIFF );
				m_ActionTime = 0.3f;
			}
		}
	}
}
