#pragma once
#include <random>
using std::uniform_real_distribution;
using std::default_random_engine;
namespace sparky
{
	class Random
	{	
	public:
		void Seed(unsigned int seed) { e.seed(seed); };
		void GenerateRandomNumber(float* number, unsigned int num, float max, float min)
		{
			
			//if (seed != -1)
			//{
			//	e.seed(seed);
			//}

			uniform_real_distribution<double> u(min, max);  
			for (unsigned int i = 0; i < num; ++i)   
				number[i] = u(e);

		}

	private:
		default_random_engine e;
		
	};
}
