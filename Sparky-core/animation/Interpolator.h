#pragma once
#include <string>
namespace sparky
{
	namespace animation
	{
		template<class T>
		class IInterpolator
		{
			virtual T Evaluate(unsigned long duration) = 0;

		};

		template<class T>
		class LinearInterpolator :public IInterpolator<T>
		{
			virtual T Evaluate()
		};
	}
}