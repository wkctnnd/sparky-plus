#pragma once
#include <maths/vec3.h>
#include <vector>
#include "PxObject.h"
namespace sparky
{
	namespace phyx
	{
		class Mass;
		class Spring;
		class PxSoftBody:public PxObject
		{
		public:


		private:
			std::vector<Mass*> m_Mass;
			std::vector<Spring*> m_Spring;



		};
	}
}