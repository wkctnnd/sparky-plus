#pragma once
#include <string>
#include "property.h"
namespace sparky
{
	namespace animation
	{
		template<class T>
		class Interpolator
		{
			virtual T Evaluate(unsigned long duration) = 0;

		};

		template<class T>
		class LinearInterpolator :public Interpolator<T>
		{
			virtual T Evaluate(Property<T> &p, unsigned int time)
			{
				
			}
		};
	}
}