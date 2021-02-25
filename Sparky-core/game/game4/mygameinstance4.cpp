#include "mygameinstance4.h"
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
using namespace sparky::render;
using namespace sparky::asset;

using namespace sparky::world;
namespace sparky
{
	namespace game
	{
		void MyGameInstance4::Init()
		{
			m_Log = new Logger("camerparam.txt");
			m_AssetManager = new asset::AssetManager();


			m_AssetManager->LoadAsset("/model/game4/taobaosucai.obj");
	


			m_Scene = new Scene();
			m_Scene->Initialize();
			world::GScene = m_Scene;
		 
			m_AssetResource = (RawMesh*)m_AssetManager->GetAsset("Content/Asset/StaticMesh/taobaosucai");
			m_MaterialResource = (Material*)m_AssetManager->GetAsset("Content/Asset/Material/taobaosucai");

			m_Lobby = new Lobby4(m_Scene, m_AssetResource, m_MaterialResource);

		
			m_CameraRoot = new Actor();
	
		
			Actor* righteye = new Actor();
			m_RightCamera = righteye->AddComponent<sparky::world::CameraComponent>();
			righteye->GetTransform()->SetLocalPosition(float3(0, 0, -5));



			m_Scene->AddActor(m_CameraRoot);
		 
			m_CameraRoot->Attach(righteye);

			AnimationComponent* animcomp = m_CameraRoot->AddComponent<AnimationComponent>();
			CameraController* controller = new CameraController();
			animcomp->SetController(controller);


		}


		void MyGameInstance4::Update()
		{
 

		}

		void MyGameInstance4::PostRender()
		{
			
	
	
		}

	}
}