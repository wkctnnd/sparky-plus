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
		class PhotoRenderer;
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

	namespace world
	{
		class Scene;
		class CameraComponent;
	}

	namespace game
	{
		class GameInstance;
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
		sparky::render::PhotoRenderer *m_Renderer;
		sparky::asset::AssetLoader *m_AssetLoader;
		sparky::particle::ParticleManager *m_ParticleManager;
		sparky::phyx::PxWorld* m_Pxworld;
		sparky::world::CameraComponent* m_CameraComponent;
		sparky::world::Scene* m_Scene;


		//这么写,目前单线程
		game::GameInstance* m_GameInstance;
		/*sparky::render::ph*/
	};


	static Engine* GEngine;
}
