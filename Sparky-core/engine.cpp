#include "engine.h"

#include "graphics/shader/graphicsshader.h"
#include "graphics/shader/computeshader.h"
#include "render/FluidRenderer.h"
#include "render/mesh.h"
#include "utils/timer.h"
#include "render/ParticleRenderer.h"
#include "particle/particlemanager.h"
using namespace sparky::render;
using namespace sparky::particle;
namespace sparky
{
	Timer Engine::GlobalTimer;
	void Engine::Initialize()
	{
		
		FluidRenderer::FluidParam param;
		//render(param);
		//render.Initialize();
		m_Renderer = new ParticleRenderer();
		m_Renderer->Initialize();
		Mesh* smokemesh = Mesh::Load("autoload");
		m_ParticleManager = new ParticleManager();
		m_ParticleManager->Initialize();
		m_ParticleManager->CreateParticleSystem();
		m_Renderer->AddRenderable(m_ParticleManager->GetRenderable());
		//render->AddSmokeVolume(smokemesh);
	}
	void Engine::Loop()
	{
		GlobalTimer.Begin();

		m_ParticleManager->Update();
		m_Renderer->Update();
		GlobalTimer.Stop();
		std::cout << GlobalTimer;
		m_Renderer->RenderScene();
	}

}
