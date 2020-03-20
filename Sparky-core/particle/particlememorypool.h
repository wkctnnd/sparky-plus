#pragma once
#include "Particle.h"
#include "particleemitter.h"
#include "particlesystem.h"
#include <vector>

namespace sparky
{
	namespace particle
	{
		const int MaxParticleMemoryPool = 10;
		class ParticleMemoryPool
		{
		public:
			void Initialize(unsigned int systemcount, unsigned int emittercount, unsigned int particlecount, unsigned int id);
			Particle * GetParticle();
			ParticleEmitter* GetParticleEmitter();
			ParticleSystem* GetParticleSystem();
			unsigned int GetPoolId() { return m_PoolId; }
			
			unsigned int GetActiveParticleCount();
		private:
		
			Particle * m_Particles;
			ParticleEmitter* m_ParticleEmitters;
			ParticleSystem* m_ParticleSystems;

			unsigned int m_SystemCount;
			unsigned int m_ParticleCount;
			unsigned int m_EmitterCount;

			unsigned int m_CurrentSystemId;
			unsigned int m_CurrentParticleId;
			unsigned int m_CurrentEmitterId;

			unsigned int m_ActiveParticleCount;
			unsigned int m_ActiveSystemCount;
			unsigned int m_ActiveEmitterCount;

			unsigned int m_PoolId;

			std::vector<Particle*> m_FreeParticles;
			std::vector<ParticleEmitter*> m_FreeParticleEmitters;
			std::vector<ParticleSystem*> m_FreeParticleSystems;

	
		};
	}
}
