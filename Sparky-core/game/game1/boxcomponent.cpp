
#include "BoxComponent.h"
#include "world/component/animationcomponent.h"
#include "box.h"
using namespace sparky::world;

namespace sparky
{
	namespace game
	{


		void BoxComponent::PreUpdate()
		{
		}

		//玩家按键后恢复碰撞属性，并且脱离玩家5秒
		void BoxComponent::Update()
		{


		}
		void BoxComponent::PostUpdate()
		{

		}

		//第一次碰到玩家后 跟随玩家并且关闭碰撞属性，直至玩家按键后恢复碰撞属性，并且脱离玩家5秒
		void BoxComponent::OnCollided(std::vector<phyx::HitPointInfo>& hitpointinfos)
		{
			bool isCollidewithplayer = false;
			for (int i = 0; i < hitpointinfos.size(); i++)
			{

				if (hitpointinfos[i].Actor->GetName().compare("Button") == 0)
				{
					((Box*)m_Owner)->SetSelect(3);
					world::RigidBodyComponent *rigidcomp = (RigidBodyComponent *)m_Owner->GetComponent<RigidBodyComponent>();
 
					//m_Owner->GetTransform()->AttachTo(*hitpointinfos[0].Actor->GetTransform());
					rigidcomp->SetEnable(false);
					return;
				}
				if (hitpointinfos[i].Actor->GetName().compare("Player") == 0)
				{
					isCollidewithplayer = true;
				}
			}
		 
				if (isCollidewithplayer == true)
				{
					((Box*)m_Owner)->SetSelect(1);
					world::RigidBodyComponent *rigidcomp = (RigidBodyComponent *)m_Owner->GetComponent<RigidBodyComponent>();
					m_Owner->GetTransform()->AttachTo(*hitpointinfos[0].Actor->GetTransform());
					m_Owner->GetTransform()->SetLocalPosition(float3(0, 0, -6));
					rigidcomp->SetEnable(false);
				}
			 
		}




	}


}

