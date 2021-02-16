#pragma once
#include "maths/vec2.h"
#include <vector>
using namespace sparky::maths;
namespace sparky
{
	namespace game
	{
		struct quad
		{
			quad():max(0,0),min(0,0)
			{
				
			}
			quad(float2 center, float2 size)
			{
				this->max = center + size / 2;
				this->min = center - size / 2;
			}
			//quad(float3 min, float3 max)
			//{
			//	this->max = max;
			//	this->min = min;
			//}
			float2 min;
			float2 max;
		};
		class Map
		{
		public:


			void AddWall(quad &w)
			{
				m_Wall = w;
				m_Border = 50;
			}
			bool AddBox(quad &q)
			{
 
				for (int i=0;i<m_Boxes.size();i++)
				{
					float2 test0,test1;
					test0 = q.min - m_Boxes[i].max;
					test1 = m_Boxes[i].min - q.max;
					if (!(test0.x>0||test0.y>0||test1.x>0||test1.y>0))
					{
						
						return false;
					}
				}
				m_Boxes.push_back(q);
				return true;


			}


			bool CheckPoint(float2 pt)
			{
				for (int i=0;i<m_Boxes.size();i++)
				{
					if (!(pt.x<(m_Boxes[i].min.x )||pt.y<(m_Boxes[i].min.y )||pt.x>m_Boxes[i].max.x ||pt.y>m_Boxes[i].max.y))
					{
						return false;
					}
				}

				if ((pt.x<(m_Wall.min.x + m_Border) || pt.y<(m_Wall.min.y + m_Border) || pt.x>m_Wall.max.x - m_Border || pt.y>m_Wall.max.y - m_Border))
				{
					return false;
				}

				return true;
			}

		private:
			std::vector<quad> m_Boxes;
			float m_Border;
			quad m_Wall;
		};
	}
}
