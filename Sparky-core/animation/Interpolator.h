#pragma once
#include <string>
#include <map>
namespace sparky
{
	namespace animation
	{

	 
		class KeyValueCollection;

		enum InterpolatorType
		{
			Linear_Type,
			TypeNum
		};

		class InterpolatorBase
		{
		public:
			InterpolatorBase(KeyValueCollection* keyvalues) :m_keyValues(keyvalues) {}
			virtual void Evaluate(unsigned long duration) {};

			int GetUniqueKey()
			{
				//m_keyValue->GetUniqueKey();
				return 0;
			}
			
		protected:
		

			KeyValueCollection * m_keyValues;
		};


		class LinearInterpolator :public InterpolatorBase
		{
		public:
			LinearInterpolator(KeyValueCollection* keyvalues):InterpolatorBase(keyvalues)
			{}
			virtual void Evaluate(unsigned int currenttime)
			{
				 
			}

		/*	static LinearInterpolator<T>* GetInterpolater(unsigned int properid)
			{
				auto result = m_Interpolaters.find(properid);
				if (result == m_Interpolaters::end())
				{
					LinearInterpolator<T> interpolator = new LinearInterpolator<T>();
					m_Interpolaters.insert(std::make_pair<unsigned int, LinearInterpolator<T>*>(properid, interpolator));
					return interpolator;
				}
				return *result;
			}*/
			std::map<unsigned int, LinearInterpolator*> m_Interpolaters;
		};
	}
}