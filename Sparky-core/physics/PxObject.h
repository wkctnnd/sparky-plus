#pragma once
#include "maths/vec3.h"
#include <vector>

using namespace sparky::maths;
namespace sparky
{
	namespace phyx
	{
		class Mass;
		class Spring;
		enum PxObjectType
		{
			SOFT_BODY,
			RIGID_BODY
		};

		struct Force
		{
			float3 position;
			float3 force;
		};
		class PxObject
		{
		public:
			virtual PxObjectType GetType() = 0;
			virtual void ApplyForce(std::vector<Force>& force) = 0;
			virtual void Simulate(float time) = 0;
			//virtual void GetRenderData() = 0;
		private:
 


		};
	}
}
