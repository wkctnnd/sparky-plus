#pragma once
#include "particlememorypool.h"
#include "particlemanager.h"
namespace sparky
{
	namespace particle
	{
	
		class ParticleMempoolManager
		{
		public:

			void Initialize(unsigned int systemcount, unsigned int emittercount, unsigned int particlecount, unsigned int poolcount);
			ParticleMemoryPool* GetPool(unsigned int id) { return &m_MemPool[id]; };
			ParticleMemoryPool* GetBestFitPool();
			static ParticleMempoolManager *INSTANCE();
			

		private:
			ParticleMempoolManager() {}
			ParticleMemoryPool* m_MemPool;
			int m_PoolCount;
			static ParticleMempoolManager *m_Instance;
		};
	}
}
