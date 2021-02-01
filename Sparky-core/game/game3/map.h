#pragma once
#include "maths/vec3.h"
#include <vector>
using namespace sparky::maths;
namespace sparky
{
	namespace game
	{
		struct quad
		{
			quad(float3 min, float3 max)
			{
				this->max = max;
				this->min = min;
			}
			float3 min;
			float3 max;
		};
		class Map
		{
		public:


			void AddWall(quad &w)
			{
				m_Wall = w;
			}
			bool AddBox(quad &q)
			{

			}

		private:
			std::vector<quad> m_Boxes;

			quad m_Wall;
		};
	}
}
