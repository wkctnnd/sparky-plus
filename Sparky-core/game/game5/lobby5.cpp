#include "Lobby5.h"
#include "Asset/rawmesh.h"
using namespace sparky::asset;
namespace sparky
{
	namespace game
	{

		float Lobby5::m_LobbyX;
		float Lobby5::m_LobbyY;
		float Lobby5::m_LobbyZ;
		Lobby5::Lobby5(class Scene* scene, asset::RawMesh* fabricmesh, asset::Material* fabricmat)
		{
			//µÿ√Ê
			//m_Fabric = new Actor();
		 

			

			for (int i=0;i<5;i++)
			{
				for (int j=0;j<5;j++)
				{
					float3 offset(0, 0, 0);
					Actor* part = new Actor();
					StaticMeshRendererComponent* meshcomponent = part->AddComponent<StaticMeshRendererComponent>();
					meshcomponent->AddStaticMesh(fabricmesh);

					//Material* material = new Material();
					//material->SetDiffuseColor(0.455, 0.305, 0.305, 1);
					meshcomponent->AddMaterial(fabricmat);
					TransformComponent* tc = part->GetTransform();
					offset.x += 1.162*i;
					offset.y += 1.189*j;
					tc->SetLocalPosition(offset);
					tc->SetLocalRotation(float3(90, 0, 0));
					Attach(part);
				}
			}
			
		 
		

		


			scene->AddActor(this);


			 
		}
	}
}