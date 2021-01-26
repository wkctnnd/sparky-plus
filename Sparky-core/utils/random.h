#pragma once
#include <random>
using std::uniform_real_distribution;
using std::default_random_engine;
namespace sparky
{
	//enum DistributeType
	//{
	//	Uniform_Distribute,
	//	Normal_Distribute
	//};
	class Random
	{	
	public:
		void Seed(unsigned int seed) { e.seed(seed); };
		void GenUniformRandomNumber(float* number, unsigned int num, float max, float min)
		{
			
			//if (seed != -1)
			//{
			//	e.seed(seed);
			//}

			uniform_real_distribution<double> u(min, max);  
			for (unsigned int i = 0; i < num; ++i)   
				number[i] = u(e);

		}

		void GenNormalRandomNumber(float* number, unsigned int num, float mean, float variance)
		{

			std::normal_distribution<double> n(mean, variance);
			for (int i = 0; i < num; i++)
			{
				float v = n(e);
				number[i] = v;
			}
	 
		}

	private:
		default_random_engine e;
		
	};
}
