#include "mygameinstance3.h"
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
		void MyGameInstance3::Init()
		{
			m_Log = new Logger("camerparam.txt");
			m_AssetManager = new asset::AssetManager();


			m_AssetManager->LoadAsset("/model/game3/cube.obj");
			m_AssetManager->LoadAsset("/model/game3/sphere.obj");
			m_AssetManager->LoadAsset("/model/game3/Pyramid.obj");
			m_AssetManager->LoadAsset("/model/game3/lobby.obj");

			m_CubeResource = (RawMesh*)m_AssetManager->GetAsset<RawMesh>("Content/Asset/StaticMesh/DefaultMesh0");
			m_BallResource = (RawMesh*)m_AssetManager->GetAsset<RawMesh>("Content/Asset/StaticMesh/DefaultMesh1");
			m_CentrumResource = (RawMesh*)m_AssetManager->GetAsset<RawMesh>("Content/Asset/StaticMesh/DefaultMesh2");
			m_LobbyResource = (RawMesh*)m_AssetManager->GetAsset<RawMesh>("Content/Asset/StaticMesh/DefaultMesh3");


			m_Scene = new Scene();
			m_Scene->Initialize();
			world::GScene = m_Scene;

			
			m_Lobby = new Lobby3(m_Scene, m_LobbyResource,m_CubeResource,m_BallResource, m_CentrumResource);

		
			m_CameraRoot = new Actor();
			//cameraroot->Attach(camera)

			Actor* lefteye = new Actor();
			m_LeftCamera = lefteye->AddComponent<sparky::world::CameraComponent>();
			lefteye->GetTransform()->SetLocalPosition(float3(0, 0, 5));

			Actor* righteye = new Actor();
			m_RightCamera = righteye->AddComponent<sparky::world::CameraComponent>();
			righteye->GetTransform()->SetLocalPosition(float3(0, 0, -5));



			m_Scene->AddActor(m_CameraRoot);
			m_CameraRoot->Attach(lefteye);
			m_CameraRoot->Attach(righteye);

			AnimationComponent* animcomp = m_CameraRoot->AddComponent<AnimationComponent>();
			CameraController* controller = new CameraController();
			animcomp->SetController(controller);

			
			ColorRenderTarget  crt;
			crt.texture = new RenderTexture2D(1920, 1080, graphics::Format::RGBA);
			crt.action = Clear_Store;
			std::vector<ColorRenderTarget*> crts;
			crts.push_back(&crt);

			DepthStencilRenderTarget dsrt;
			dsrt.action = DepthStencilRenderTargetAction::DepthClearDontStore_StecilClearDontStore;
			dsrt.texture = new RenderTexture2D(1920, 1080, graphics::Format::DEPTH24STENCILl8);
			m_LeftCamera->SetRenderTarget(crts, &dsrt);
			//很奇怪在此处调用，无反应
			//m_CameraComponent->GetRenderTargetInfo()->Bind();



			ColorRenderTarget  crt2;
			crt2.texture = new RenderTexture2D(1920, 1080, graphics::Format::RGBA);
			crt2.action = Clear_Store;
			std::vector<ColorRenderTarget*> crts2;
			crts2.push_back(&crt2);

			DepthStencilRenderTarget dsrt2;
			dsrt2.action = DepthStencilRenderTargetAction::DepthClearDontStore_StecilClearDontStore;
			dsrt2.texture = new RenderTexture2D(1920, 1080, graphics::Format::DEPTH24STENCILl8);
			m_RightCamera->SetRenderTarget(crts2, &dsrt2);

		}


		void MyGameInstance3::Update()
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