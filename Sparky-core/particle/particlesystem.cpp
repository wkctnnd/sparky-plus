#include "particlesystem.h"
#include "particlemempoolmanager.h"
namespace sparky
{
	namespace particle
	{
		void ParticleSystem::AddEmitter()
		{
			ParticleMemoryPool* pool = ParticleMempoolManager::INSTANCE()->GetPool(m_MemoryPoolId);
			ParticleEmitter* emitter = pool->GetParticleEmitter();

			emitter->Initialize(this, POINT_EMIT_TYPE);
			m_Emitters.push_back(emitter);
		}

		void ParticleSystem::Update()
		{
			for (unsigned int i = 0;i<m_Emitters.size();i++)
			{
				m_Emitters[i]->GenerateParticles();
				m_Emitters[i]->UpdateParticleState();
			}
		}
	}
}