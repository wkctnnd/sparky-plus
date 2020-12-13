#pragma once
#include "vec3.h"
#include "mat4.h"
#include "vec4.h"
namespace sparky
{
	namespace maths
	{
		class Shpere
		{
		public:
			Shpere() {};
			Shpere(float3 center, float radius) :m_Center(center), m_Radius(radius) {}
			 
			void Transform(mat4& mat)
			{
				float4 temp = mat * float4(m_Center.x, m_Center.y, m_Center.z, 1);
				m_Center.x = temp.x;
				m_Center.y = temp.y;
				m_Center.z = temp.z;
			}
			float3 m_Center;
			float m_Radius;

			//float3 m_Max;
			//float3 m_Min;

		};
	}
}
