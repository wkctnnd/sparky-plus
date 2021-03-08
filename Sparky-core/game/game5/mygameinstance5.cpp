#include "mygameinstance5.h"
#include "world/component/cameracomponent.h"
#include "world/component/transformcomponent.h"
#include "world/component/animationcomponent.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "utils/fileutils.h"
#include "Asset/objloader.h"
#include "Asset/AssetLoader.h"
#include "world/scene.h"
#include "world/actor.h"
#include "Asset/AssetManager.h"
#include "game/game3/cameracontroller.h"

#include "graphics/rendertarget.h"
#include "graphics/texture/texture.h"
#include "graphics/texture/rendertexture2d.h"

#include "utils/timer.h"
#include "engine.h"
#include <sstream>
#include "Asset/rawmesh.h"
using namespace sparky::render;
using namespace sparky::asset;

using namespace sparky::world;
namespace sparky
{
	namespace game
	{
		void MyGameInstance5::Init()
		{
			m_Log = new Logger("camerparam.txt");
			m_AssetManager = new asset::AssetManager();


			m_AssetManager->LoadAsset("/model/game5/fabric.obj");
	


			m_Scene = new Scene();
			m_Scene->Initialize();
			world::GScene = m_Scene;
		 
			m_AssetResource =  m_AssetManager->GetAsset<RawMesh>("Content/Asset/StaticMesh/DefaultMesh0");
			//m_MaterialResource = (Material*)m_AssetManager->GetAsset("Content/Asset/Material/fabric");
			m_MaterialResource = new asset::Material();
			
			m_Lobby = new Lobby5(m_Scene, m_AssetResource, m_MaterialResource);

	
	
		
			Actor* righteye = new Actor();
			m_RightCamera = righteye->AddComponent<sparky::world::CameraComponent>();
			righteye->GetTransform()->SetLocalPosition(float3(0, 5, 0));



			m_Scene->AddActor(righteye);
		 
	 
		}


		void MyGameInstance5::Update()
		{
 

		}

		void MyGameInstance5::PostRender()
		{
			
	
	
		}

	}
}