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
using namespace sparky::render;
using namespace sparky::particle;
using namespace sparky::asset;
using namespace sparky::phyx;
namespace sparky
{
	Timer Engine::GlobalTimer;
	void Engine::Initialize()
	{

		//FluidRenderer::FluidParam param;
		//render(param);
		//render.Initialize();
		//m_Renderer = new ParticleRenderer();
		//m_Renderer->Initialize();
		
		/*m_AssetLoader = AssetLoader::INSTANCE();
		m_AssetLoader->Initialize();
		Mesh* smokemesh = Mesh::Load("autoload");

		m_AssetLoader->LoadFile("JiaoTan.FBX");
		RawSkinMesh* rawskinmesh = m_AssetLoader->GetRawSkinMesh(0);*/
		//SkeletonClip* skeletonpos = m_AssetLoader->GetClip(0);
		/*Skeleton* skeleton = m_AssetLoader->GetSkeleton(0);
		SkinMesh* skinmesh = new SkinMesh(rawskinmesh);
		SkeletalMesh *skeletalmesh = new SkeletalMesh(skinmesh, skeleton);
		unsigned int count = m_AssetLoader->GetAnimationLayerCount();
		AnimationStack* animstack = new AnimationStack("");
		for (unsigned int i = 0; i < 1; i++)
		{
			animstack->AddLayer(m_AssetLoader->GetAnimationLayer(0),1);
		}*/
	/*	AnimationStack* animstack2 = new AnimationStack("");
		for (unsigned int i = 0; i < 1; i++)
		{
			animstack2->AddLayer(m_AssetLoader->GetAnimationLayer(1), 1);
		}
		AnimationStack* animstack3 = new AnimationStack("");
		for (unsigned int i = 0; i < 1; i++)
		{
			animstack3->AddLayer(m_AssetLoader->GetAnimationLayer(2), 1);
		}*/

		//Controller *controller = new Controller();
		//std::vector<AnimationStack*> stacks;
		//stacks.push_back(animstack);
		////stacks.push_back(animstack2);
		////stacks.push_back(animstack3);
		//controller->Initialize(stacks);
		//skeletalmesh->SetController(controller);
		//	
		//m_Renderer = new SkinMeshRenderer(skeletalmesh);
		//m_Renderer->Initialize();

		m_Renderer = new PhyxRenderer();
		m_Renderer->Initialize();
		
		m_Pxworld = new PxWorld();

		
		/*m_ParticleManager = new ParticleManager();
		m_ParticleManager->Initialize();
		m_ParticleManager->CreateParticleSystem();*/

		
		//m_Renderer->AddRenderable(skeletalmesh);
		//render->AddSmokeVolume(smokemesh);
	}
	void Engine::Loop()
	{
		GlobalTimer.Begin();

		//m_ParticleManager->Update();
		m_Renderer->Update();
	
		PxSoftBody *body = PxSoftBody::CreateDefaultCube(0);
		m_Pxworld->AddObject(body);
		m_Pxworld->Simulate(GlobalTimer.GetElapsemillionseconds());

		
		std::vector<PxObject*> result;
		m_Pxworld->FetchResult(result);

		m_Renderer->Update();
		m_Renderer->RenderScene();
		GlobalTimer.Stop();

		//long elapse = Engine::GlobalTimer.GetElapsemillionseconds();
		//long remain = 330 - elapse;
		//if (remain > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remain));

		//elapse = Engine::GlobalTimer.GetElapsemillionseconds();
		//std::cout << elapse << std::endl;
	}

}
