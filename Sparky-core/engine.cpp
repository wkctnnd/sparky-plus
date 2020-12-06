#include "engine.h"

#include "graphics/shader/graphicsshader.h"
#include "graphics/shader/computeshader.h"
#include "render/FluidRenderer.h"
#include "render/mesh.h"
#include "utils/timer.h"
#include "render/ParticleRenderer.h"
#include "particle/particlemanager.h"

#include "Asset/AssetLoader.h"
#include "Asset/rawskinmesh.h"
#include "Asset/skeletalpose.h"
#include "render/skeletalmesh.h"
#include "render/skinmesh.h"
#include "render/skinmeshrenderer.h"
#include "animation/animationstack.h"
#include "render/OceanRender.h"
#include "animation/controller.h"
#include <thread>
#include <chrono>
#include "render/phyxRender.h"
#include "physics/PxWorld.h"
#include "physics/PxSoftBody.h"
#include "world/scene.h"
#include "world/actor.h"
#include "world/component/cameracomponent.h"
#include "world/component/transformcomponent.h"
#include "graphics/rendertarget.h"
#include "graphics/texture/texture.h"
#include "graphics/texture/rendertexture2d.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "utils/fileutils.h"
#include "render/photorenderer.h"
#include "Asset/objloader.h"
#include "maths/util.h"
using namespace sparky::render;
using namespace sparky::particle;
using namespace sparky::asset;
using namespace sparky::phyx;
using namespace sparky::world;
namespace sparky
{
	Timer Engine::GlobalTimer;
	void Engine::Initialize()
	{
		/*m_Renderer = new PhyxRenderer();
		m_Renderer->Initialize();

		m_Pxworld = new PxWorld();
		m_Pxlink.push_back(0);
		m_Pxlink.push_back(1);
		m_Pxlink.push_back(2);
		m_Pxlink.push_back(2);
		m_Pxlink.push_back(3);
		m_Pxlink.push_back(0);

		m_Pxlink.push_back(4);
		m_Pxlink.push_back(6);
		m_Pxlink.push_back(5);
		m_Pxlink.push_back(6);
		m_Pxlink.push_back(4);
		m_Pxlink.push_back(7);

		m_Pxlink.push_back(0);
		m_Pxlink.push_back(5);
		m_Pxlink.push_back(1);
		m_Pxlink.push_back(5);
		m_Pxlink.push_back(0);
		m_Pxlink.push_back(4);

		m_Pxlink.push_back(3);
		m_Pxlink.push_back(2);
		m_Pxlink.push_back(6);
		m_Pxlink.push_back(6);
		m_Pxlink.push_back(7);
		m_Pxlink.push_back(3);

		m_Pxlink.push_back(4);
		m_Pxlink.push_back(0);
		m_Pxlink.push_back(7);
		m_Pxlink.push_back(7);
		m_Pxlink.push_back(0);
		m_Pxlink.push_back(3);

		m_Pxlink.push_back(1);
		m_Pxlink.push_back(5);
		m_Pxlink.push_back(6);
		m_Pxlink.push_back(1);
		m_Pxlink.push_back(6);
		m_Pxlink.push_back(2);
		PxSoftBody *body = PxSoftBody::CreateDefaultCube(0);*/



	//	m_Pxworld->AddObject(body);
		
		m_Scene = new sparky::world::Scene();
		m_Scene->Initialize();
		m_Renderer = new sparky::render::PhotoRenderer(m_Scene);
		m_Renderer->Initialize();
		Actor* camera = new Actor();
		sparky::world::StaticMeshRendererComponent* camerameshcomponent = camera->AddComponent<StaticMeshRendererComponent>();
		

		sparky::world::CameraComponent* cameracomponet = camera->AddComponent<sparky::world::CameraComponent>();
		m_Scene->AddActor(camera);
		Actor* photoedActor = new Actor();
		m_Scene->AddActor(photoedActor);
		sparky::world::StaticMeshRendererComponent* staticmeshcom = photoedActor->AddComponent<sparky::world::StaticMeshRendererComponent>();

		//m_AssetLoader->LoadFile("model//hanoi.obj");
		//int rawsectioncount = m_AssetLoader->GetRawStaticMeshCount();
		//for (int i=0;i<rawsectioncount;i++)
		//{
		//	staticmeshcom->AddStaticMesh(m_AssetLoader->GetRawStaticMesh(i));
		//}
		//
		RawMesh* mesh = new RawMesh();
		std::string fullrelativepath = FileUtile::GetCurrentWorkingDirectory() + std::string(AssetFilePath) + "model//ucp201.obj";
		objLoader::LoadMesh(fullrelativepath.c_str(), *mesh);
		staticmeshcom->AddStaticMesh(mesh);
		camerameshcomponent->AddStaticMesh(mesh);
		ColorRenderTarget  crt;
		crt.texture = new RenderTexture2D(512, 512, graphics::Format::RGBA);
		crt.action = Clear_Store;
		std::vector<ColorRenderTarget*> crts;
		crts.push_back(&crt);

		DepthStencilRenderTarget dsrt;
		dsrt.action = DepthStencilRenderTargetAction::DepthClearDontStore_StecilClearDontStore;
		dsrt.texture = new RenderTexture2D(512, 512, graphics::Format::DEPTH24STENCILl8);
		cameracomponet->SetRenderTarget(crts, &dsrt);
		/*m_ParticleManager = new ParticleManager();
		m_ParticleManager->Initialize();
		m_ParticleManager->CreateParticleSystem();*/
		
		//Mesh *m = Mesh::Load("test.obj");
		
		//m_Renderer->AddRenderable(skeletalmesh);
		//render->AddSmokeVolume(smokemesh);

		std::vector<CameraComponent*> cameras = m_Scene->GetRoot()->GetChildrenComponents<CameraComponent>();
		if (cameras.size() > 0)
		{
			m_CameraComponent = cameras[0];
		}

	}

	float angleA = 0;
	float angleB = 0;
	float angleC = 0;
	float angleD = 0;
	float radius = 100;
	

	void Engine::Loop()
	{
		GlobalTimer.Begin();

		//m_ParticleManager->Update();
		//m_Renderer->Update();
		
		Actor *camera = m_CameraComponent->GetOwner();
		TransformComponent* component = camera->GetTransform();

		float3 lookatpoistion(0, 0, 0);
		float3 cameraposition;
		if (angleA < 2 * 3.1415926)
			angleA += 0.1;
		if (component)
		{
			cameraposition.x = radius * Util::Sin(angleA);
			cameraposition.z = radius * Util::Cos(angleA);
			cameraposition.y = radius * Util::Sin(angleB);
			component->SetLocalPosition(cameraposition);

			float3 direction = cameraposition - lookatpoistion;
			component->RotateForwardTo(direction);


		}

		m_Scene->UpdateTransform();

		graphics::RenderTexture* rt = m_CameraComponent->GetColorRenderTexture(0);
		graphics::RenderTexture* drt = m_CameraComponent->GetDepthStencilRenderTexture();
		//m_Pxworld->Update(Engine::GlobalTimer.GetElapsemillionseconds());
		//m_Pxworld->Simulate(Engine::GlobalTimer.GetElapsemillionseconds());
		//m_CameraComponent->GetOwner()->GetTransform()->RotateYAxis(10);

 
		//std::vector<PxObject*> result;
		//m_Pxworld->FetchResult(result);
		//for (int i=0;i<result.size();i++)
		//{
		//	PxSoftBody* softbody = (PxSoftBody*)(result[i]);
		//	std::vector<float3> pos;
		//	for (int j=0;j< m_Pxlink.size();j++)
		//	{
		//		pos.push_back(softbody->m_Mass[m_Pxlink[j]]->pos);
		//	}
		// 
		//	//m_Renderer->Update(i, pos);
		//}
		//m_Renderer->Update();
		m_Renderer->PostUpdate();
	//	m_CameraComponent->GetRenderTargetInfo()->Bind();
		//m_Renderer->RenderScene();
		m_Renderer->RenderSceneTest();
		
		GlobalTimer.Stop();
		
		std::string time = GlobalTimer.GetCurrentTime();
		std::string path = FileUtile::GetCurrentWorkingDirectory()+string("\\..\\Assets\\output\\");
		std::string temp = GlobalTimer.GetCurrentTime();

		string::iterator it;

		for (it = temp.begin(); it < temp.end(); it++)

		{

			if (*it == ':')

			{

				temp.erase(it);

				it--;
 

			}

		}
		
		//std::string colorpath = path + temp + "color.bmp";
		//rt->SaveToDisk(colorpath);

		//m_CameraComponent->GetRenderTargetInfo()->Bind();
		//std::string depthpath = path + temp + "depth.bmp";
		//m_Renderer->RenderSceneDepth();
		//rt->SaveToDisk(depthpath);
		
		//m_CameraComponent->GetRenderTargetInfo()->UnBind();
		glFlush();
		//long elapse = Engine::GlobalTimer.GetElapsemillionseconds();
		//long remain = 330 - elapse;
		//if (remain > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remain));

		//elapse = Engine::GlobalTimer.GetElapsemillionseconds();
		//std::cout << elapse << std::endl;
	}

}
