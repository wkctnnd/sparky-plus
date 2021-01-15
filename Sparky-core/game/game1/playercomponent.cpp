#include "Playercomponent.h"
#include "world/component/animationcomponent.h"
#include "playercontroller.h"
#include "physics/pxShape.h"

using namespace sparky::game;
namespace sparky
{
	namespace game
	{
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

		void PlayerComponent::OnCollided(std::vector<phyx::HitPointInfo>& hitpointinfos)
		{
			

			if (hitpointinfos.size()>0)
			{
				if (hitpointinfos[0].Actor->GetName().compare("Box")==0|| hitpointinfos[0].Actor->GetName().compare("Button") == 0)
				{

				}
				else
				{
					AnimationComponent *animcomp = (AnimationComponent *)m_Owner->GetComponent<AnimationComponent>();
					//RigidBodyComponent *rigidcomp = (RigidBodyComponent *)m_Owner->GetComponent<RigidBodyComponent>();
					PlayerComponent* con = (PlayerComponent*)animcomp->GetController();

					//animcomp->SetEnable(false);
					GetOwner()->GetTransform()->Translate(float3(0, 0, 1));
					m_FronzonTime = 100;
				}
			}

		}

	}
}
