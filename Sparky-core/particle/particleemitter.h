#pragma once
#include <list>
#include "maths/vec3.h"
#include "asset/material.h"
#include "utils/random.h"
//#include "render/particlemesh.h"
using namespace sparky::maths;


namespace sparky
{
	namespace asset
	{
		class Material;
	}
	namespace render
	{
		struct PerEmitterVertex;
		class ParticleMesh;
	}
}
using namespace sparky::render;
namespace sparky
{
	namespace particle
	{
		class Particle;
		
		class ParticleSystem;
		enum EmitType
		{
			POINT_EMIT_TYPE,
			DISK_EMIT_TYPE
		};

		class ParticleEmitter
		{

			friend ParticleMesh;
		public:
			ParticleEmitter(EmitType type);
			ParticleEmitter(){
				int a = 1;
			};

			void GenerateParticles();
			void UpdateParticleState();

			void Initialize(ParticleSystem* o ,EmitType type);
			void GetParticlesVertex(float3*);
			void GenVertices();
			unsigned int GetParicleCount() { return m_Particles.size(); }
			float3 GetPosition() { return m_Position; }
			float Distance2Camera();
		protected:
			std::list<Particle*> m_Particles;
			asset::Material* m_Material;

			float3 m_Direction;
			float3 m_Position;
			float3 m_Speed;

			//PerEmitterVertex*  m_QuadVertices;
			float3* m_Vertices;
			unsigned int m_MaxSize;
			unsigned int m_ActiveCount;

		private:
			ParticleSystem* m_Owner;
			EmitType m_EmitType; 
			Random random;

		
			
		};

		class QuadParticleEmitter :public ParticleEmitter
		{
			friend ParticleMesh;
		};


		class MeshParticleEmitter :public ParticleEmitter
		{
			friend ParticleMesh;

		};
	}
}
