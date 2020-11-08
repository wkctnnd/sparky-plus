#pragma once
#include "maths/vec3.h"
#include <vector>
#include "maths/AABox.h"
#include "PxObject.h"
using namespace sparky::maths;
namespace sparky
{
	namespace phyx
	{
		class Mass
		{
		public:
			Mass(float mass, float3 pos, float3 vec, float3 acc)
			{
				this->mass = mass;
				this->pos = pos;
				this->vec = vec;
				this->acc = acc;
			}
			float mass;       //mass
			float3 pos;    //position
			float3 vec;    //velocity
			float3 acc;    //acceleration
			float3 force;    //force

			float3 nextpos;
			float3 nextvec;
			std::vector<Spring*> Springs;
		};

		class Spring {
		public:
			Spring(float k, float len, int m1, int m2)
			{
				this->k = k;
				this->len = len;
				this->m1 = m1;
				this->m2 = m2;
			}
			float k;       //constriant
			float len;      //rest length
			//float oriL;
			int m1;
			int m2;

			float3 force;
		};

		class PxSoftBody:public PxObject
		{
		public:
			PxObjectType GetType() { return SOFT_BODY; }
			static PxSoftBody* CreateDefaultCube(int c);
			virtual void ApplyForce(std::vector<Force>& force);
			void Simulate(float time);
			void AddMass(float mass, float3 pos, float3 vec, float3 acc);
			void AddSpring(float k, float len, int m1, int m2);
		private:
			Mass* FindNearestMass(float3 position);

			std::vector<Mass*> m_Mass;
			std::vector<Spring*> m_Spring;

			AABox m_BoundBox;
			float m_Grvavity;
			//void *UpdateDelegate(int);
		};
	}
}