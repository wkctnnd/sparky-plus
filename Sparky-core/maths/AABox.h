#pragma once
#include "vec3.h"
#include "maths/mat4.h"
namespace sparky
{
	namespace maths
	{
		class AABox
		{
		public:
			AABox() {};
			AABox(float3 center, float3 extension) :m_Center(center), m_Extension(extension) {}
			void Merge(AABox& box);
			bool IsContain(float3 point);
			bool IsOverlap(AABox& box);
			void Transform(mat4& mat)
			{
				m_Center = mat * float4(m_Center.x, m_Center.y, m_Center.z, 1);
			}
			float3 m_Center;
			float3 m_Extension;

			//float3 m_Max;
			//float3 m_Min;

		};
	}
}
