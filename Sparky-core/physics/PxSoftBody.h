#pragma once
#include "maths/vec3.h"
#include <vector>
#include "maths/AABox.h"
#include "PxObject.h"
using namespace sparky::maths;
//https://blog.csdn.net/ZJU_fish1996/article/details/53056109?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.pc_relevant_is_cache&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.pc_relevant_is_cache

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
			Spring(float ks, float kd, float len, int m1, int m2)
			{
				this->ks = ks;
				this->kd = kd;
				this->len = len;
				this->m1 = m1;
				this->m2 = m2;
				this->oriL = len;
			 
			}
			
			float kd;
			float ks;       //constriant
			float len;      //rest length
			float oriL;
			int m1;
			int m2;

			float damping;
			float3 force;
		};

		class PxSoftBody:public PxObject
		{
		public:
			PxSoftBody(world::Actor* sc):PxObject(sc) { m_Grvavity = -10; }
			PxObjectType GetType() { return SOFT_BODY; }
			static PxSoftBody* CreateDefaultCube(int c);
			virtual void ApplyForce(std::vector<Force>& force);
			void Simulate(float time);
			void Update(float time);
			void AddMass(float mass, float3 pos, float3 vec, float3 acc);
			void AddSpring(float ks, float kd, float len, int m1, int m2);
			void GetRenderData(std::vector<float3> &vertexarray);

			std::vector<Mass*> m_Mass;
			std::vector<Spring*> m_Spring;
		private:
			Mass* FindNearestMass(float3 position);

			

			AABox m_BoundBox;
			float m_Grvavity = -1.0;

			float m_Ground = -10;
			//void *UpdateDelegate(int);
		};
	}
}