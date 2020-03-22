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
			//m_Emitters.push_back(emitter);

			Insert(emitter);
		}

		void ParticleSystem::Update()
		{
			for (unsigned int i = 0;i<m_Emitters.size();i++)
			{
				m_Emitters[i]->GenerateParticles();
				m_Emitters[i]->UpdateParticleState();
				m_Emitters[i]->GenVertices();
			}
		}

		void ParticleSystem::Initialize(vec3 campos)
		{
			m_CameraPos = campos;
		}

		void ParticleSystem::Sort()
		{

		}

		void ParticleSystem::Insert(ParticleEmitter* e)
		{
			m_Emitters.push_back(e);
			ParticleEmitter* t = 0;
			float length = (e->GetPosition() - m_CameraPos).length();

			for (auto iterator = m_Emitters.begin(); iterator < m_Emitters.end(); iterator++)
			{

				vec3 temp = (*iterator)->GetPosition() - m_CameraPos;
				float lengthtest = temp.length();
				if (length - lengthtest < 0)
				{
					t = *iterator;
				}
			}
		}
	
	}
}