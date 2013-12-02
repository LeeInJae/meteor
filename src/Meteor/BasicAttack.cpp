#include "stdafx.h"
#include "BasicAttack.h"
#include "ResourceManager.h"


static const ResourceId animationType = L"effect_slash";


CBasicAttack::CBasicAttack()
{
}


CBasicAttack::~CBasicAttack(void)
{
}


bool CBasicAttack::LoadAnimation()
{
	ResourceId directionList[] = { L"_up", L"_up_right", L"_right", L"_down_right", L"_down", L"_down_left", L"_left", L"_up_left" };

	for each ( ResourceId direction in directionList )
	{
		ResourceId animationId = animationType + direction;
		CAnimationInfo * animationInfo = CResourceManager::GetInstance().GetAnimationInfo( animationId );
		CAnimation * animation = animationInfo->CreateAnimation();
		animation->SetSpeed(8);
		m_Animation[ animationId ] = animation;
		SafeRelease( animationInfo );
	}

	return true;
}


bool CBasicAttack::Update( float deltaTime )
{
	return CSkill::Update( deltaTime );
}


CAnimation * CBasicAttack::GetAnimation() const
{
	ResourceId animationId = animationType;

	switch( m_Target->GetDirection() )
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



void CBasicAttack::ApplySkill( CGameObject * target )
{
	m_Target = target;
	CAnimation * animation = GetAnimation();
	animation->Stop( true );
	animation->Play( 10, false );
}
