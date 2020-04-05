#pragma once
#include "utils/timer.h"
namespace sparky{
	namespace render {
		class FluidRenderer;
		class ParticleRenderer;
	}
	namespace asset
	{
		class AssetLoader;
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
		sparky::asset::AssetLoader *m_AssetLoader;
		sparky::particle::ParticleManager *m_ParticleManager;
	};
}
