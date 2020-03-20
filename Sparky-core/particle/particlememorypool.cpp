#pragma once
#include "particlememorypool.h"

namespace sparky
{
	namespace particle
	{

		void ParticleMemoryPool::Initialize(unsigned int systemcount, unsigned int emittercount, unsigned int particlecount, unsigned int id)
		{
			m_Particles = new Particle[particlecount];
			m_ParticleEmitters = new ParticleEmitter[emittercount];
			m_ParticleSystems = new ParticleSystem[systemcount];
			for (unsigned int i = 0; i < systemcount; i++)
			{
				m_ParticleSystems[i].SetPoolId(id);
			}

			m_SystemCount = systemcount;
			m_ParticleCount = particlecount;
			m_EmitterCount = emittercount;

			m_CurrentSystemId = 0;
			m_CurrentParticleId = 0;
			m_CurrentEmitterId = 0;

			m_ActiveParticleCount = 0;

			m_PoolId = id;
		}
		Particle * ParticleMemoryPool::GetParticle()
		{
			Particle* newparticle;
			if (m_CurrentParticleId < m_ParticleCount)
			{
				newparticle = &m_Particles[m_CurrentParticleId];
				m_CurrentParticleId++;

			}
			else
			{
				newparticle = m_FreeParticles.back();
				m_FreeParticles.pop_back();
			}
			m_ActiveParticleCount++;
			return newparticle;
		}


		ParticleEmitter* ParticleMemoryPool::GetParticleEmitter()
		{
			ParticleEmitter* newparticleemitter;
			if (m_CurrentEmitterId < m_ParticleCount)
			{
				newparticleemitter = &m_ParticleEmitters[m_CurrentEmitterId];
				m_CurrentEmitterId++;

			}
			else
			{
				newparticleemitter = m_FreeParticleEmitters.back();
				m_FreeParticleEmitters.pop_back();
			}
			return newparticleemitter;
		}

		ParticleSystem* ParticleMemoryPool::GetParticleSystem()
		{
			ParticleSystem* newparticlesystem;
			if (m_CurrentParticleId < m_ParticleCount)
			{
				newparticlesystem = &m_ParticleSystems[m_CurrentEmitterId];
				m_CurrentEmitterId++;

			}
			else
			{
				newparticlesystem = m_FreeParticleSystems.back();
				m_FreeParticleSystems.pop_back();
			}
			return newparticlesystem;
		}
	 
		unsigned int ParticleMemoryPool::GetActiveParticleCount()
		{
			return m_ActiveParticleCount;
		}

		
	}
}
