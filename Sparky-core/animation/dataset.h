#pragma once
#include <string>
namespace sparky
{
	namespace animation
	{

		
		template<class T>
		class DataSet
		{
			virtual T Evaluate(unsigned long duration) = 0;


		private:
			
		};


	}
}