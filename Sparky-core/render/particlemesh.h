#pragma once
#include "graphics/buffers/DynamicBuffer.h"
#include "render/material.h"
#include <vector>
#include "maths/vec3.h"
#include "renderable.h"
#include "graphics/buffers/vertexarray.h"
using namespace sparky::graphics;
using namespace sparky::render;
using namespace sparky::maths;

class sparky::render::Material;
namespace sparky
{
	namespace particle
	{
		class ParticleEmitter;
		class ParticleSystem;
	}
}
using namespace sparky::particle;
namespace sparky
{
	namespace render
	{
	
		struct PerEmitterVertex
		{
			ParticleEmitter* emitter;
			vec3* vertices;
			unsigned int count;

		};

		struct MergedData
		{
			unsigned int vertexstart;
			unsigned int vertexcount;
			Material* material;
		};
		class ParticleMesh:public Renderable
		{
		public:
			ParticleMesh(unsigned int size, vec3 cameraposition);
			void Update(PerEmitterVertex**  m_QuadVertices, unsigned int* emittersize, unsigned int poolsize);

		private:
			void Sort(PerEmitterVertex**  m_QuadVertices, unsigned int* emittersize, unsigned int poolsize);
			void Merge();
			void render();
		private:
			DynamicBuffer * m_MergedBuffer;


			//tempuse




			////////////////////////////////////////

			VertexArray  m_Vao;
			std::vector<PerEmitterVertex>  m_EmitterParticle;
			//float DistanceToCamera(vec3 pos);
			vec3 m_CameraPosition;
			//sort for emitter position
			std::vector<PerEmitterVertex*> m_SortEmitterParticles;

			float* m_VertexData;
			unsigned int m_MaxSize;
			unsigned int m_DataSize;
		};
	}
}
