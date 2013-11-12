#include "stdafx.h"
#include "PC.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "AnimationInfo.h"

#define WALK_SPEED 128

CPC::CPC(void)
{
}

CPC::~CPC(void)
{
	for ( auto animation : m_Animation )
		animation->Release();
	m_Animation.clear();
}

bool CPC::LoadAnimation()
{
	std::wstring animationIdList[] = { L"character_walk_left", L"character_walk_right", L"character_walk_up", L"character_walk_down" };

	for each ( std::wstring animationId in animationIdList )
	{
		CAnimationInfo * animationInfo = CResourceManager::GetInstance().GetAnimationInfo( animationId );
		CAnimation * animation = animationInfo->CreateAnimation();
		Position position = {
			static_cast<float>( CGameManager::GetInstance().GetWidth() ) / 2,
			static_cast<float>( CGameManager::GetInstance().GetHeight() ) / 2,
			BASE_CENTER, DOWN };
		animation->SetPosition( position );
		m_Animation.push_back( animation );
		SafeRelease( animationInfo );
	}

	return true;
}

bool CPC::Update( float deltaTime )
{
	CGameObject::Update( deltaTime );

	if ( m_Status == WALK )
	{	
		switch( m_Position.direction )
		{
		case LEFT:
			// agebreak : ���� 1000�� ������ �ʿ� ����, deltaTime�� �ʴ����� ������ �� ��������
			Move( ( -WALK_SPEED ) * deltaTime * 0.001f, 0 );
			break;

		case RIGHT:
			Move( ( WALK_SPEED ) * deltaTime * 0.001f, 0 );
			break;

		case UP:
			Move( 0, ( -WALK_SPEED ) * deltaTime * 0.001f );
			break;

		case DOWN:
			Move( 0, ( WALK_SPEED ) * deltaTime * 0.001f );
			break;

		default:
			break;
		}
	}

	return true;
}

CAnimation * CPC::GetAnimation() const
{

	// agebreak : �ִϸ��̼� ����Ʈ�� ������� ������ �� �ִٰ� �����ϴ� �ڵ�� ���� ����
	// Ű���� ���� Map�� ���·� ����°��� �� ���� 
	CAnimation * animation = m_Animation[3];

	switch( m_Position.direction )
	{
	case LEFT:
		animation = m_Animation[0];
		break;

	case RIGHT:
		animation = m_Animation[1];
		break;

	case UP:
		animation = m_Animation[2];
		break;

	case DOWN:
		animation = m_Animation[3];
		break;
	}

	if ( m_Status == WALK )
		animation->SetSpeed( 8 );
	else if ( m_Status == STAND )
		animation->SetSpeed( 0 );

	return animation;
}
