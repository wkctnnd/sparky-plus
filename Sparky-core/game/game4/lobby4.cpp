#include "Lobby4.h"
#include "Asset/rawmesh.h"
using namespace sparky::asset;
namespace sparky
{
	namespace game
	{

		float Lobby4::m_LobbyX;
		float Lobby4::m_LobbyY;
		float Lobby4::m_LobbyZ;
		Lobby4::Lobby4(class Scene* scene, asset::RawMesh* lobbymesh, asset::Material* lobbymat)
		{
			//µØÃæ
			m_HouseBox = new Actor();
		 

			StaticMeshRendererComponent* meshcomponent = m_HouseBox->AddComponent<StaticMeshRendererComponent>();
			meshcomponent->AddStaticMesh(lobbymesh);

			//Material* material = new Material();
			//material->SetDiffuseColor(0.455, 0.305, 0.305, 1);
			meshcomponent->AddMaterial(lobbymat);
		 
			Attach(m_HouseBox);

		


			scene->AddActor(this);


			 
		}
	}
}