#pragma once
#include "vec3.h"
namespace sparky
{
	namespace maths
	{
		class AABox
		{
		public:
			void Merge(AABox& box);
			bool IsContain(float3 point);
			bool IsOverlap(AABox& box);

			float3 m_Center;
			float3 m_Extension;

		};
	}
}
