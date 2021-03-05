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
		Lobby5::Lobby5(class Scene* scene, asset::RawMesh* lobbymesh, asset::Material* lobbymat)
		{
			//µÿ√Ê
			m_Fabric = new Actor();
		 
			for (int i=0;i<500;i++)
			{
				for (int j=0;j<500;j++)
				{

				}
			}
			StaticMeshRendererComponent* meshcomponent = m_Fabric->AddComponent<StaticMeshRendererComponent>();
			meshcomponent->AddStaticMesh(lobbymesh);

			//Material* material = new Material();
			//material->SetDiffuseColor(0.455, 0.305, 0.305, 1);
			meshcomponent->AddMaterial(lobbymat);
		 
			Attach(m_Fabric);

		


			scene->AddActor(this);


			 
		}
	}
}