#include "stdafx.h"
#include "Skill.h"

bool CSkill::LoadAnimation()
{
	ResourceId directionList[] = { L"_up", L"_up_right", L"_right", L"_down_right", L"_down", L"_down_left", L"_left", L"_up_left" };

	for each ( ResourceId direction in directionList )
	{
		ResourceId animationId = m_SkillName + direction;
		CAnimationInfo * animationInfo = CResourceManager::GetInstance().GetAnimationInfo( animationId );
		CAnimation * animation = animationInfo->CreateAnimation();
		animation->SetSpeed(8);
		m_Animation[ animationId ] = animation;
		SafeRelease( animationInfo );
	}

	return true;
}

CAnimation * CSkill::GetAnimation() const
{
	ResourceId animationId = m_SkillName;

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
