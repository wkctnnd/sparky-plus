#pragma once
#include "maths/vec3.h"
namespace sparky {
	namespace maths {
		class Util
		{
		public:
			static int ClosestPowerOfTwo(int t)
			{
			/*	int temp = ~t + 1;
				return t + temp;*/
				return t;
			}

			static float DistanceTo(vec3 src, vec3 dis)
			{
				float temp = (dis - src).Dot(dis - src);
				temp = sqrt(temp);
				return temp;
			}

			template<class T>
			static T Max(T a, T b)
			{
				if (a > b)
				{
					return a;
				}
				return b;
			}
		};
	}
}