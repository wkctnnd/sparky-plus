#pragma once
#include "utils/timer.h"
namespace sparky{
	namespace render {
		class FluidRenderer;
		class ParticleRenderer;
	}

	namespace particle
	{
		class ParticleManager;
	}
}
namespace sparky
{
	
	class Engine
	{
	public:
		 void Loop();
		 void Initialize();

	public:

		static Timer GlobalTimer;

	private:
		sparky::render::ParticleRenderer *m_Renderer;

		sparky::particle::ParticleManager *m_ParticleManager;
	};
}
