#include "mygameinstance3.h"
#include "world/component/cameracomponent.h"
#include "world/component/transformcomponent.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "utils/fileutils.h"
#include "Asset/objloader.h"
#include "Asset/AssetLoader.h"
#include "world/scene.h"
#include "world/actor.h"
#include "Asset/AssetManager.h"
 
using namespace sparky::render;
using namespace sparky::asset;

using namespace sparky::world;
namespace sparky
{
	namespace game
	{
		void MyGameInstance3::Init()
		{
			
			m_AssetManager = new asset::AssetManager();

			RawMesh* mesh = new RawMesh();

			m_AssetManager->LoadAsset("/model/game3/cube.obj");
			m_AssetManager->LoadAsset("/model/game3/sphere.obj");
			m_AssetManager->LoadAsset("/model/games/lobby.obj");

			m_CubeResource = (RawMesh*)m_AssetManager->GetAsset("/context/model/game3/cube_mesh");
			m_BallResource = (RawMesh*)m_AssetManager->GetAsset("/context/model/game3/sphere_mesh");
			m_LobbyResource = (RawMesh*)m_AssetManager->GetAsset("/context/model/games/lobby_mesh");



			m_Scene = new Scene();
			m_Scene->Initialize();
			world::GScene = m_Scene;


			m_Lobby = new Lobby3(m_Scene, m_LobbyResource,m_CubeResource,m_BallResource, m_CentrumResource);

		

			Actor* camera = new Actor();
			m_CameraComponent = camera->AddComponent<sparky::world::CameraComponent>();
		 
			camera->GetTransform()->SetLocalPosition(float3(0, 10, 10));
			
		}


		void MyGameInstance3::Update()
		{
			float temp;
	

		}

	}
}