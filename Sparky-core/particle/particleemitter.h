#pragma once
#include <list>
#include "maths/vec3.h"
#include "render/material.h"
#include "utils/random.h"
using namespace sparky::maths;
using namespace sparky::render;
class sparky::render::Material;
namespace sparky
{
	namespace render
	{
		struct PerEmitterVertex;
		class ParticleMesh;
	}
}
 
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
			void GetParticlesVertex(vec3*);
			void GenVertices();
			unsigned int GetParicleCount() { return m_Particles.size(); }
			vec3 GetPosition() { return m_Position; }
			float Distance2Camera();
		protected:
			std::list<Particle*> m_Particles;
			Material* m_Material;

			vec3 m_Direction;
			vec3 m_Position;
			vec3 m_Speed;

			//PerEmitterVertex*  m_QuadVertices;
			vec3* m_Vertices;
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
