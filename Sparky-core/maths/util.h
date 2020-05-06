#pragma once
#include "maths/vec3.h"
#include <math.h>

#define Pi 3.1415026
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

			static float DistanceTo(float3 src, float3 dis)
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

			template<class T>
			static T Min(T a, T b)
			{
				if (a < b)
				{
					return a;
				}
				return b;
			}


			static float Sin(float radian)
			{
				return sin(radian);
			}

			static float Cos(float radian)
			{
				return cos(radian);
			}

			static float RadianFromDegree(float degree)
			{
				return Pi * degree / 180.0f;
			}

		};
	}
}