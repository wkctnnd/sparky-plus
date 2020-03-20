#pragma once
#include "particleemitter.h"
#include <vector>
namespace sparky
{
	namespace particle
	{
		class ParticleMesh;
		class ParticleSystem
		{
			friend ParticleEmitter;
			friend ParticleMesh;
		public:
			void AddEmitter();
			void Update();
			void SetPoolId(unsigned int id) { m_MemoryPoolId = id; }
			ParticleEmitter* GetEmitter(unsigned int id) { return m_Emitters[id]; }
			unsigned int GetEmitterCount() { return m_Emitters.size(); }
			//void GetVertexPool(float* )
		private:
			std::vector<ParticleEmitter*> m_Emitters;
			unsigned int m_MemoryPoolId;
		};
	}
}
