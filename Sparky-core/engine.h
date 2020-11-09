#pragma once
#include "utils/timer.h"
#include <vector>
namespace sparky{
	namespace render {
		class FluidRenderer;
		class ParticleRenderer;
		class SkinMeshRenderer;
		class OceanRenderer;
		class PhyxRenderer;
		
	}
	namespace asset
	{
		class AssetLoader;
	}
	namespace particle
	{
		class ParticleManager;
	}

	namespace phyx
	{
		class PxWorld;
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
		std::vector<int> m_Pxlink;
		sparky::render::PhyxRenderer *m_Renderer;
		sparky::asset::AssetLoader *m_AssetLoader;
		sparky::particle::ParticleManager *m_ParticleManager;
		sparky::phyx::PxWorld* m_Pxworld;

		
	};
}
