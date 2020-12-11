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
 

			assetloader.LoadFile("amongus_astro_still.obj");
			//objLoader::LoadMesh(fullrelativepath.c_str(), *m_Astronautmeshresource);

			world::GScene = new Scene();
			world::GScene->Initialize();

			m_Astronautmeshresource = assetloader.GetRawStaticMesh(0);
			m_Player = new Player(world::GScene, m_Astronautmeshresource);

			
 
			assetloader2.LoadFile("amongus_lobby.obj");
			m_Lobby = new Lobby(world::GScene, assetloader2.GetRawStaticMesh(0));

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



		void MyGameInstance::Update()
		{
			
		}

	}
}