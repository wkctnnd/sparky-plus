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


			m_AssetManager->LoadAsset("/model/game4/ÌÔ±¦µêÆÌÇåÓÆËØ²Ä.obj");
	


			m_Scene = new Scene();
			m_Scene->Initialize();
			world::GScene = m_Scene;

			
			m_Lobby = new Lobby4(m_Scene, m_LobbyResource,m_CubeResource,m_BallResource, m_CentrumResource);

		
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
			float temp;
			static int i = 0;
			if (i < 15)
			{
				PathPoint orignpoint = m_Lobby->GetPathPoint(0);
				PathPoint ppoint = m_Lobby->GetPathPoint(i);
				m_CameraRoot->GetTransform()->SetLocalPosition(ppoint.position);
				std::ostringstream out;
				out << ppoint.position.x - orignpoint.position.x << " " << ppoint.position.z - orignpoint.position. z<< " " << ppoint.cameraangle - orignpoint.cameraangle;
				m_Log->Log(out.str());
				Quaternion r = Quaternion::FromEulerXYZ(0, ppoint.cameraangle, 0);
				m_CameraRoot->GetTransform()->SetLocalRotation(float3(0, ppoint.cameraangle, 0));
				i++;
			}

		}

		void MyGameInstance3::PostRender()
		{
			
			//static int index = 0;
			//if (index==15)
			//{
			//	exit(0);
			//}
			//std::string path = FileUtile::GetCurrentWorkingDirectory() + string("\\..\\Assets\\output\\");
			////std::string temp = GlobalTimer.GetCurrentTime();


			//std::string colorpath = path  + "color"+ std::to_string(index) +".bmp";

			//graphics::RenderTexture* rt = m_CameraComponent->GetColorRenderTexture(0);

			//rt->SaveToDisk(colorpath);
			//index++;
			//glFlush();

			static int index = 0;
			
			if (index == 15)
			{
				exit(0);
			}

			for (int i = 0; i < m_Scene->GetCameraCount(); i++)
			{
				world::CameraComponent*  camera = m_Scene->GetCamera(i);


				std::string path = FileUtile::GetCurrentWorkingDirectory() + string("\\..\\Assets\\output\\");
				//std::string temp = GlobalTimer.GetCurrentTime();


				std::string colorpath = path + "color" + std::to_string(i) + std::to_string(index) + ".bmp";

				graphics::RenderTexture* rt = camera->GetColorRenderTexture(0);

				rt->SaveToDisk(colorpath);
				

			}
			index++;
	
		}

	}
}