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
#include "graphics/rendertarget.h"
#include "graphics/texture/texture.h"
#include "graphics/texture/rendertexture2d.h"
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
		m_Renderer = new PhyxRenderer();
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
		PxSoftBody *body = PxSoftBody::CreateDefaultCube(0);



		m_Pxworld->AddObject(body);

		m_Scene = new sparky::world::Scene();
		m_Scene->Initialize();

		Actor* camera = new Actor();
		sparky::world::CameraComponent* cameracomponet = camera->AddComponent<sparky::world::CameraComponent>();
		m_Scene->AddActor(camera);

		ColorRenderTarget  crt;
		crt.texture = new RenderTexture2D(512, 512, graphics::Format::RGB);
		crt.action = Clear_Store;
		std::vector<ColorRenderTarget*> crts;
		crts.push_back(&crt);

		DepthStencilRenderTarget dsrt;
		dsrt.action = DepthStencilRenderTargetAction::DepthClearDontStore_StecilClearDontStore;
		dsrt.texture = new RenderTexture2D(512, 512, graphics::Format::DEPTH24);
		cameracomponet->SetRenderTarget(crts, &dsrt);
		/*m_ParticleManager = new ParticleManager();
		m_ParticleManager->Initialize();
		m_ParticleManager->CreateParticleSystem();*/

		
		//m_Renderer->AddRenderable(skeletalmesh);
		//render->AddSmokeVolume(smokemesh);

		std::vector<CameraComponent*> cameras = m_Scene->GetRoot()->GetChildrenComponents<CameraComponent>();
		if (cameras.size() > 0)
		{
			m_CameraComponent = cameras[0];
		}

	}
	void Engine::Loop()
	{
		GlobalTimer.Begin();

		//m_ParticleManager->Update();
		//m_Renderer->Update();
	

		
		//m_Pxworld->Update(Engine::GlobalTimer.GetElapsemillionseconds());
		m_Pxworld->Simulate(Engine::GlobalTimer.GetElapsemillionseconds());
		m_CameraComponent->GetOwner()->GetTransform()->RotateYAxis(10);
		
		std::vector<PxObject*> result;
		m_Pxworld->FetchResult(result);
		for (int i=0;i<result.size();i++)
		{
			PxSoftBody* softbody = (PxSoftBody*)(result[i]);
			std::vector<float3> pos;
			for (int j=0;j< m_Pxlink.size();j++)
			{
				pos.push_back(softbody->m_Mass[m_Pxlink[j]]->pos);
			}
		 
			m_Renderer->Update(i, pos);
		}
		//m_Renderer->Update();
		m_Renderer->RenderScene();
		GlobalTimer.Stop();
		
		graphics::RenderTexture* rt = m_CameraComponent->GetColorRenderTexture(0);
		
		//long elapse = Engine::GlobalTimer.GetElapsemillionseconds();
		//long remain = 330 - elapse;
		//if (remain > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remain));

		//elapse = Engine::GlobalTimer.GetElapsemillionseconds();
		//std::cout << elapse << std::endl;
	}

}
