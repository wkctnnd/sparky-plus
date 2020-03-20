#include "particlemesh.h"
#include "particle/particlesystem.h"
#include "particle/particleemitter.h"
#include "maths/util.h"
#include <string.h>
namespace sparky{
	namespace render
	{
		ParticleMesh::ParticleMesh(unsigned int size, vec3 cameraposition)
		{
			m_CameraPosition = cameraposition;
			m_MaxSize = size;
			m_VertexData = new float[size * 6];
			m_MergedBuffer = new DynamicBuffer(0, size * 6, 3);
			m_Vao.addBuffer(m_MergedBuffer, 0);
		}
		//void ParticleMesh::Merge2Buffer(ParticleSystem* system)
		//{
		//	std::vector<ParticleEmitter*> &emitters = system->m_Emitters;
		//	for (int i = 0; i < emitters.size(); i++)
		//	{
		//		auto &particles = emitters[i]->m_Particles;
		//		for (int j = 0; j < particles.size(); j++)
		//		{

		//		}
		//	}
		//}

		void ParticleMesh::Update(PerEmitterVertex**  m_QuadVertices, unsigned int* emittersize, unsigned int poolsize)
		{
			Sort(m_QuadVertices, emittersize, poolsize);
			Merge();

		}

		void ParticleMesh::Sort(PerEmitterVertex** m_QuadVertices, unsigned int* emittersize, unsigned int poolsize)
		{
			/*unsigned int emittercount = 0;
			for (unsigned int i = 0;i<poolsize;i++)
			{
				emittercount += emittersize[i];
			}*/
			unsigned int *offset = new unsigned int[poolsize];
			for (unsigned int i = 0; i < poolsize; i++)
			{
				offset[i] = 0;
			}
			while (true)
			{

				int chosenid = -1;
				float chosendis = 10000000000;
				for (unsigned int i = 0; i < poolsize; i++)
				{
					if (offset[i] < emittersize[i])
					{
						float dis = Util::DistanceTo(m_QuadVertices[i][offset[i]].emitter->m_Position, m_CameraPosition);
						if (dis < chosendis)
						{
							dis = chosendis;
							chosenid = i;
						}
					}


				}

				if (chosenid != -1)
				{
					
					m_SortEmitterParticles.push_back(&m_QuadVertices[chosenid][offset[chosenid]]);
					offset[chosenid]++;
				}
				else
					break;
				
			}
		}
		
		void ParticleMesh::Merge()
		{
			float* data = m_VertexData;
			for (unsigned int i = 0; i < m_SortEmitterParticles.size(); i++)
			{
				unsigned int count = m_SortEmitterParticles[i]->count;
				memcpy(data, m_SortEmitterParticles[i]->vertices, count  * 4);
				
				data += count * 6;
				m_DataSize += m_SortEmitterParticles[i]->count;
			}
		}
		
		void ParticleMesh::render()
		{

			void* data = m_MergedBuffer->Lock(0, m_DataSize);
			memcpy(data, m_VertexData, m_DataSize * 4);
			m_MergedBuffer->unLock();
			m_Vao.bind();
			glDrawArrays(GL_TRIANGLES, 0, m_DataSize);
			m_Vao.unBind();
			m_SortEmitterParticles.clear();
			m_DataSize = 0;
		}
	}
}