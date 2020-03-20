#include "particlemempoolmanager.h"
namespace sparky
{
	namespace particle
	{
		ParticleMempoolManager * sparky::particle::ParticleMempoolManager::m_Instance = 0;

		void ParticleMempoolManager::Initialize(unsigned int systemcount, unsigned int emittercount, unsigned int particlecount, unsigned int poolcount)
		{
			m_MemPool = new ParticleMemoryPool[poolcount];
			m_PoolCount = poolcount;

			unsigned int persystemcount = systemcount / poolcount;
			unsigned int peremittercount = emittercount / poolcount;
			unsigned int perparticlecount = particlecount / poolcount;
			for (int i = 0; i < poolcount; i++)
			{
				m_MemPool[i].Initialize(persystemcount, peremittercount, perparticlecount, i);
			}

			//m_MemPool[poolcount - 1].Initialize(systemcount - (poolcount - 1)*persystemcount, emittercount - (poolcount - 1)*peremittercount, particlecount - (poolcount - 1)*perparticlecount);
		}

		ParticleMemoryPool* ParticleMempoolManager::GetBestFitPool()
		{
			ParticleMemoryPool* bestpool = 0;
			unsigned int LeastActiveParticleNum = 1000000000;
			for (int i = 0; i < m_PoolCount; i++)
			{
				if (LeastActiveParticleNum > m_MemPool[i].GetActiveParticleCount())
				{
					LeastActiveParticleNum = m_MemPool[i].GetActiveParticleCount();
					bestpool = &m_MemPool[i];
				}
			}
			return bestpool;
		}

		ParticleMempoolManager* ParticleMempoolManager::INSTANCE()
		{
			if (m_Instance)
			{
				return m_Instance;
			}
			else
			{
				m_Instance = new ParticleMempoolManager();
			}
			return m_Instance;
		}

	};
}

