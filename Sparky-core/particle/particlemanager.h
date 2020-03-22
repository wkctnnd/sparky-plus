#pragma once
#include <vector>
#include "particlememorypool.h"
#include "particlesystem.h"
#include "Render/particlemesh.h"

#define DEFAULT_MAX_MEMORY_MANAGER_PARTICLES  5000
#define DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_EMITTERS 10
#define DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_SYSTEMS 10
#define DEFAULT_NUM_MEMORY_POOLS  1


using namespace sparky::render;
namespace sparky
{
	namespace particle
	{
		class ParticleMempoolManager;

		class ParticleManager
		{
		public:
			//ParticleManager(){}
			void Initialize();
			void Update();
			~ParticleManager() {};
			void GetQuadVertices();
			void PrepareRenderData();
			void CreateParticleSystem();
			void SortInThread(unsigned int id);
			void MergeThreads();
			ParticleMesh* GetRenderable() { return m_ParticleMesh; };
		private:
			std::vector<ParticleSystem*> m_Systems[DEFAULT_NUM_MEMORY_POOLS];
			ParticleMempoolManager *m_MemPoolMgr;
			ParticleMesh *m_ParticleMesh;

			std::list<ParticleEmitter*> m_SortedEmitters[DEFAULT_NUM_MEMORY_POOLS];
			//ParticleEmitter* m_SortedEmitters[DEFAULT_NUM_MEMORY_POOLS*DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_SYSTEMS*DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_EMITTERS];
			PerEmitterVertex*  m_QuadVertices[DEFAULT_NUM_MEMORY_POOLS];
			unsigned int* EmitterSize[DEFAULT_NUM_MEMORY_POOLS];

		};
	}
}
