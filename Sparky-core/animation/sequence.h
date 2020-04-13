#pragma once
#include <string>
namespace sparky
{
	namespace animation
	{
		template<class T>
		class Sequence
		{
			virtual T Evaluate(unsigned long duration) = 0;

		};

		template<class T>
		class LinearInterpolator :public Interpolator<T>
		{
			virtual T Evaluate()
		};
	}
}