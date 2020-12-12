#pragma once
#include "vec3.h"
namespace sparky
{
	namespace maths
	{
		class Shpere
		{
		public:
			Shpere() {};
			Shpere(float3 center, float radius) :m_Center(center), m_Radius(radius) {}
			 

			float3 m_Center;
			float m_Radius;

			//float3 m_Max;
			//float3 m_Min;

		};
	}
}
