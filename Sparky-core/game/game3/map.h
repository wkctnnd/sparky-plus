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
			quad():max(0,0,0),min(0,0,0)
			{
				
			}
			quad(float3 center, float3 size)
			{
				this->max = center + size / 2;
				this->min = center - size / 2;
			}
			//quad(float3 min, float3 max)
			//{
			//	this->max = max;
			//	this->min = min;
			//}
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
 
				for (int i=0;i<m_Boxes.size();i++)
				{
					float3 test0,test1;
					test0 = q.min - m_Boxes[i].max;
					test1 = m_Boxes[i].min - q.max;
					if (test0.x>0||test0.y>0||test0.z>0||test1.x>0||test1.y>0||test1.z>0)
					{
						m_Boxes.push_back(q);
						return true;
					}
				}

				return false;


			}

		private:
			std::vector<quad> m_Boxes;

			quad m_Wall;
		};
	}
}
