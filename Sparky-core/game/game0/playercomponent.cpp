#include "Playercomponent.h"
#include "world/component/animationcomponent.h"
#include "playercontroller.h"


using namespace sparky::game;

void PlayerComponent::Update()
{
	if (m_FronzonTime > 0)
	{
		m_FronzonTime--;
	}
	else
	{
		AnimationComponent *animcomp = (AnimationComponent *)m_Owner->GetComponent<AnimationComponent>();
		animcomp->SetEnable(true);
	}

}

void PlayerComponent::OnCollided()
{
	AnimationComponent *animcomp = (AnimationComponent *)m_Owner->GetComponent<AnimationComponent>();
	RigidBodyComponent *rigidcomp = (RigidBodyComponent *)m_Owner->GetComponent<RigidBodyComponent>();
	PlayerComponent* con = (PlayerComponent*)animcomp->GetController();
	 
	animcomp->SetEnable(false);
	m_FronzonTime = 100;
	 
}
 