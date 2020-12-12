#include "mygameinstance.h"
#include "world/component/cameracomponent.h"
#include "world/component/transformcomponent.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "utils/fileutils.h"
#include "Asset/objloader.h"
#include "Asset/AssetLoader.h"
#include "world/scene.h"
#include "world/actor.h"
#include "player.h"
#include "robot.h"
#include "lobby.h"
using namespace sparky::render;
using namespace sparky::asset;

using namespace sparky::world;
namespace sparky
{
	namespace game
	{
		void MyGameInstance::Init()
		{
			AssetLoader assetloader;
			AssetLoader assetloader2;
			RawMesh* mesh = new RawMesh();
 

			assetloader.LoadFile("/model/astronouts/amongus_astro_still.obj");
			//objLoader::LoadMesh(fullrelativepath.c_str(), *m_Astronautmeshresource);

			m_Scene = new Scene();
			m_Scene->Initialize();
			world::GScene = m_Scene;

			m_Astronautmeshresource = assetloader.GetRawStaticMesh(0);
			m_Player = new Player(m_Scene, m_Astronautmeshresource);
			
			
 
			assetloader2.LoadFile("/model/lobby/amongus_lobby.obj");
			m_Lobby = new Lobby(m_Scene, assetloader2.GetRawStaticMesh(0), assetloader2.GetMaterial(0));


			m_RandomEngine.Seed(10);


			StaticMeshRendererComponent *meshrendercom = (StaticMeshRendererComponent*)m_Player->GetComponent<StaticMeshRendererComponent>();
			RenderMaterial* mat = meshrendercom->GetMaterial(0);
			mat->SetDiffuseColor(float3(1, 0, 0));

		

	/*		m_Player = world::GScene->AddActor();
			sparky::world::StaticMeshRendererComponent* staticmeshcom = m_Player->AddComponent<sparky::world::StaticMeshRendererComponent>();
			int rawsectioncount = assetloader.GetRawStaticMeshCount();


			for (int i = 0; i < rawsectioncount; i++)
			{
				staticmeshcom->AddStaticMesh(assetloader.GetRawStaticMesh(i));
			}
*/
			
		/*	staticmeshcom = m_Lobby->AddComponent<sparky::world::StaticMeshRendererComponent>();

			
			rawsectioncount = assetloader2.GetRawStaticMeshCount();
			for (int i = 0; i < rawsectioncount; i++)
			{
				staticmeshcom->AddStaticMesh(assetloader.GetRawStaticMesh(i));
			}
		
			staticmeshcom->AddStaticMesh(mesh);*/
		}

		void MyGameInstance::GenerateRobot()
		{
			float3 position = GetRandomPosition();
			float temp;
			m_RandomEngine.GenerateRandomNumber(&temp, 1, 10, 5);
			Robot* robot = new Robot(m_Scene, m_Astronautmeshresource, temp);
			TransformComponent* tc = (TransformComponent*)robot->GetComponent<TransformComponent>();
			tc->SetLocalPosition(position);
			m_Robots.push_back(robot);
			StaticMeshRendererComponent* meshrender = (StaticMeshRendererComponent*)robot->GetComponent<StaticMeshRendererComponent>();
			
			meshrender->GetMaterial(0)->SetDiffuseColor(GetRandomColor());
		}

		void MyGameInstance::Update()
		{
			float temp;
			m_RandomEngine.GenerateRandomNumber(&temp, 1, 1, 0);
			if(temp>0.99)
				GenerateRobot();

			for (auto itr = m_Robots.begin(); itr != m_Robots.end(); itr++)
			{
				if ((*itr)->GetLife() <= 0)
				{
					(*itr)->SetActive(false);
				}

			}
		}

	}
}