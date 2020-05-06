#include "particlemanager.h"
#include "particlemempoolmanager.h"
namespace sparky
{
	namespace particle
	{
		unsigned int ParticleManager::m_MaxParticleCount = DEFAULT_MAX_MEMORY_MANAGER_PARTICLES;
		unsigned int ParticleManager::m_MaxParticleEmitterCount = DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_EMITTERS;
		unsigned int ParticleManager::m_MaxParticleSystemCount = DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_SYSTEMS;

		void ParticleManager::Update()
		{
			for (unsigned int i = 0; i < DEFAULT_NUM_MEMORY_POOLS; i++)
			{
				auto systems = m_Systems[i];
				for (unsigned int j = 0; j < systems.size(); j++)
				{
					//ParticleEmitter* emitter = *(emitters[j]);
					systems[j]->Update();
				}
			}

			GetQuadVertices();
			unsigned int ind[8] = {1,0,0,0,0,0,0,0};
			m_ParticleMesh->Update(&m_QuadVertices[0], ind, 1);
		
		}

		void ParticleManager::Initialize()
		{
			m_MemPoolMgr = ParticleMempoolManager::INSTANCE();
			m_MemPoolMgr->Initialize(DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_SYSTEMS, DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_EMITTERS, DEFAULT_MAX_MEMORY_MANAGER_PARTICLES, DEFAULT_NUM_MEMORY_POOLS);

			for (unsigned int i = 0; i < DEFAULT_NUM_MEMORY_POOLS; i++)
			{
				m_QuadVertices[i] = new PerEmitterVertex[DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_SYSTEMS];
			}
			unsigned int perparticlecount = DEFAULT_MAX_MEMORY_MANAGER_PARTICLES / DEFAULT_NUM_MEMORY_POOLS;
			//for (int i = 0; i < DEFAULT_NUM_MEMORY_POOLS; i++)
			//{
			//	m_QuadVertices[i] = new float[perparticlecount];
			//}
			//m_QuadVertices[DEFAULT_NUM_MEMORY_POOLS - 1] = new float[DEFAULT_MAX_MEMORY_MANAGER_PARTICLES - perparticlecount * (DEFAULT_NUM_MEMORY_POOLS - 1)];
			m_ParticleMesh = new ParticleMesh(DEFAULT_NUM_MEMORY_POOLS*DEFAULT_MAX_MEMORY_MANAGER_PARTICLES*DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_EMITTERS*DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_SYSTEMS, float3(0, 0, 0));
		}

		void ParticleManager::CreateParticleSystem()
		{
			ParticleMemoryPool* pool = m_MemPoolMgr->GetBestFitPool();
			ParticleSystem* system = pool->GetParticleSystem();
			system->AddEmitter();
			m_Systems[pool->GetPoolId()].push_back(system);
		}

		void ParticleManager::GetQuadVertices()
		{
			for (unsigned int i = 0; i < DEFAULT_NUM_MEMORY_POOLS; i++)
			{
				std::vector<ParticleSystem*>& system = m_Systems[i];
				for (unsigned int j = 0; j < system.size(); j++)
				{
					for (auto emittorid = 0; emittorid < system[j]->GetEmitterCount(); emittorid++)
					{
						auto emittor = system[j]->GetEmitter(emittorid);

						if (m_QuadVertices[i][j].vertices != 0)
						{
							m_QuadVertices[i][j].vertices = new float3[6 * emittor->GetParicleCount()];
							m_QuadVertices[i][j].count = 6 * emittor->GetParicleCount();
							m_QuadVertices[i][j].emitter = emittor;
						}
							
						emittor->GetParticlesVertex(m_QuadVertices[i][j].vertices);
					
					}
				}
			}
		}

		void ParticleManager::PrepareRenderData()
		{
			for (unsigned int i = 0; i < DEFAULT_NUM_MEMORY_POOLS; i++)
			{
				std::vector<ParticleSystem*>& system = m_Systems[i];
				for (unsigned int j = 0; j < system.size(); j++)
				{
					for (auto emittorid = 0; emittorid < system[j]->GetEmitterCount(); emittorid++)
					{
						auto emittor = system[j]->GetEmitter(emittorid);

						if (m_QuadVertices[i][j].vertices != 0)
						{
							m_QuadVertices[i][j].vertices = new float3[6 * emittor->GetParicleCount()];
							m_QuadVertices[i][j].count = 6 * emittor->GetParicleCount();
							m_QuadVertices[i][j].emitter = emittor;
						}

						emittor->GetParticlesVertex(m_QuadVertices[i][j].vertices);

					}
				}
			}
		}

		/*void ParticleManager::SortInThread(unsigned int id)
		{
			unsigned int offset = id *DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_SYSTEMS*DEFAULT_MAX_MEMORY_MANAGER_PARTICLE_EMITTERS;
			std::vector<ParticleSystem*>& systems = m_Systems[id];

			unsigned int i = 0;
			
			for (unsigned int j = 0; j < systems.size(); j++)
			{
				ParticleSystem* system = systems[j];
				if (j == 0)
				{
					for (unsigned int k = 0;k< system->GetEmitterCount();k++)
					{
						m_SortedEmitters[offset + i] = system->GetEmitter(k);
					}
					
				}
				else
				{
					for (unsigned int k = 0; k < system->GetEmitterCount(); k++)
					{
						unsigned int t = 0;
						for (unsigned int p = t; p < t; p++)
						{
							if (system->GetEmitter(k)<m_SortedEmitters[offset+i])
								m_SortedEmitters[offset + i] = system->GetEmitter(k);

						}
						
					}
				}
				i++;
				
			}
		}*/

		void ParticleManager::SortInThread(unsigned int id)
		{
			std::list<ParticleEmitter*>& systememitters = m_SortedEmitters[id];
			std::vector<ParticleSystem*>& systems = m_Systems[id];

			unsigned int i = 0;

		

			for (unsigned int j = 0; j < systems.size(); j++)
			{
				ParticleSystem* system = systems[j];
				if (j == 0)
				{
					for (auto iterator = systememitters.begin(); iterator != systememitters.end(); iterator++)
					{
						systememitters.push_back(*iterator);
					}

				}
				else
				{
					for (unsigned int k = 0; k < system->GetEmitterCount(); k++)
					{
						ParticleEmitter *InsertEmitter = system->GetEmitter(k);
						float len = InsertEmitter->Distance2Camera();
						auto p = systememitters.begin();
						for (auto iterator = p;iterator!=systememitters.end();)
						{
							auto temp = iterator;
							float length = system->GetEmitter(k)->Distance2Camera();
							 
							if (len < length)
							{
								if (iterator == systememitters.begin())
								{
									systememitters.push_front(InsertEmitter);
								}
								else
								{
									auto insertpoint = iterator--;
									systememitters.insert(insertpoint, InsertEmitter);
								}
								
							}
							iterator = temp;
							iterator++;
						}

					}
				}
				i++;

			}
		}

		void ParticleManager::MergeThreads()
		{
			for (unsigned int i = 0; i < DEFAULT_NUM_MEMORY_POOLS; i++)
			{
				m_MergedSortedEmitters.merge(m_SortedEmitters[i]);
			}
		}

		void ParticleManager::PostUpdate()
		{
			for (unsigned int i = 0; i < DEFAULT_NUM_MEMORY_POOLS; i++)
			{
				m_SortedEmitters[i].clear();
			 }
		}
	}
}
