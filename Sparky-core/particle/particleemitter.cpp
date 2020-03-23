#include "particleemitter.h"
#include "particlemempoolmanager.h"
#include "utils/timer.h"
#include "engine.h"

namespace sparky
{
	namespace particle
	{
		ParticleEmitter::ParticleEmitter(EmitType type)
		{
			m_EmitType = type;
		}

		void ParticleEmitter::Initialize(ParticleSystem* o ,EmitType type)
		{
			random.Seed(10);
			m_EmitType = type;
			m_Owner = o;
			m_MaxSize = ParticleManager::m_MaxParticleCount;
			m_Vertices = new vec3[m_MaxSize];
			m_ActiveCount = 0;
		}
		void ParticleEmitter::GenerateParticles()
		{
			ParticleMemoryPool* pool = ParticleMempoolManager::INSTANCE()->GetPool(m_Owner->m_MemoryPoolId);

			
			if (m_EmitType == POINT_EMIT_TYPE)
			{
				float temp[3];
				//float speed;
				random.GenerateRandomNumber(temp, 3, 1, -1);
				for (unsigned int i = 0; i < 1; i++)
				{
					Particle* newparticle = pool->GetParticle();
					newparticle->m_Life = 1.0;
					newparticle->m_Speed = vec3(temp[0], temp[1], temp[2]);
					//m_Particles.push_back(0);
					m_Particles.push_back(newparticle);
				}
			}
			
		}

		float ParticleEmitter::Distance2Camera()
		{
			return (m_Position - m_Owner->m_CameraPos).length(); 
		}

		void ParticleEmitter::GetParticlesVertex(vec3* vertexarray)
		{
			unsigned int offset = 0;
			vec3 right(1,0,0);
			vec3 up(0,1,0);
			for (auto particle = m_Particles.begin(); particle!=m_Particles.end();particle++)
			{	vertexarray[offset++] = (*particle)->m_position + right * (*particle)->m_Scale + up * (*particle)->m_Scale;
				vertexarray[offset++] = (*particle)->m_position + right * (*particle)->m_Scale - up * (*particle)->m_Scale;
				vertexarray[offset++] = (*particle)->m_position - right * (*particle)->m_Scale - up * (*particle)->m_Scale;
				vertexarray[offset++] = (*particle)->m_position + right * (*particle)->m_Scale + up * (*particle)->m_Scale;
				vertexarray[offset++] = (*particle)->m_position - right * (*particle)->m_Scale - up * (*particle)->m_Scale;
				vertexarray[offset++] = (*particle)->m_position - right * (*particle)->m_Scale + up * (*particle)->m_Scale;
			}
		}

		void ParticleEmitter::GenVertices()
		{
			unsigned int m_ActiveCount = 0;
			vec3 right(1, 0, 0);
			vec3 up(0, 1, 0);
			for (auto particle = m_Particles.begin(); particle != m_Particles.end(); particle++)
			{		
					m_Vertices[m_ActiveCount++] = (*particle)->m_position + right * (*particle)->m_Scale + up * (*particle)->m_Scale;
					m_Vertices[m_ActiveCount++] = (*particle)->m_position + right * (*particle)->m_Scale - up * (*particle)->m_Scale;
					m_Vertices[m_ActiveCount++] = (*particle)->m_position - right * (*particle)->m_Scale - up * (*particle)->m_Scale;
					m_Vertices[m_ActiveCount++] = (*particle)->m_position + right * (*particle)->m_Scale + up * (*particle)->m_Scale;
					m_Vertices[m_ActiveCount++] = (*particle)->m_position - right * (*particle)->m_Scale - up * (*particle)->m_Scale;
					m_Vertices[m_ActiveCount++] = (*particle)->m_position - right * (*particle)->m_Scale + up * (*particle)->m_Scale;
			}
		}

		void ParticleEmitter::UpdateParticleState()
		{
			float elapse = Engine::GlobalTimer.GetElapseSeconds();
			auto iterator = m_Particles.begin();

			while (iterator!=m_Particles.end())
			{

				//life control
				if ((*iterator)->m_Life - elapse <= 0)
				{
					iterator = m_Particles.erase(iterator);
					if (iterator != m_Particles.end())break;
					else continue;
				}
				(*iterator)->m_Life -= elapse;
				//update
				(*iterator)->m_position = (*iterator)->m_position - (*iterator)->m_Speed*elapse;
				iterator++;
			}

		}
	}
}