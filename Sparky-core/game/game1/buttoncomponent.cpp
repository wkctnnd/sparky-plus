
#include "buttoncomponent.h"
#include "render/rendermaterial.h" 
 
using namespace sparky::world;

namespace sparky
{
	namespace game
	{


		void ButtonComponent::PreUpdate()
		{
		}
		void ButtonComponent::Update()
		{
			if (IsOpen&&timeframe>0)
			{
				timeframe--;
				m_LeftDoor->GetTransform()->Translate(float3(-0.1, 0, 0));
				m_RightDoor->GetTransform()->Translate(float3(0.1, 0, 0));
			}
		 
		}
		void ButtonComponent::PostUpdate()
		{

		}

		//改变颜色，打开门
		void ButtonComponent::OnCollided(std::vector<phyx::HitPointInfo>& hitpointinfos)
		{
			for (int i=0;i<hitpointinfos.size();i++)
			{
				if (hitpointinfos[i].Actor->GetName().compare("Box")==0)
				{
					RenderMaterial* mat = ((StaticMeshRendererComponent*)(m_Owner->GetComponent<StaticMeshRendererComponent>()))->GetMaterial(0);
					mat->SetDiffuseColor(float4(1, 0, 0,1));
					IsOpen = true;

					m_Player->GetComponent<RigidBodyComponent>()->SetEnable(false);
				}
			}
			
		}



	}


}

