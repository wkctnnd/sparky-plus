#pragma once
#include <string>
#include "property.h"
namespace sparky
{
	namespace animation
	{

		enum InterpolatorType
		{
			Linear_Type,
			TypeNum
		};
		template<class T>
		class Interpolator
		{
			virtual T Evaluate(unsigned long duration) = 0;
			static InterpolatorType<T> *GetInterpolator(unsigned int propertyid,InterpolatorType type)
			{
				switch (type)
				{
				case sparky::animation::Linear_Type:
					return LinearInterpolator<T>::GetInterpolator(propertyid);
 
				 
				default:
					break;
				}
			}
		};

		template<class T>
		class LinearInterpolator :public Interpolator<T>
		{
			virtual T Evaluate(Property<T> &p, unsigned int lastlocation, unsigned int currenttime)
			{
				
			}

			static LinearInterpolator<T>* GetInterpolater(unsigned int properid)
			{
				auto result = m_Interpolaters.find(properid);
				if (result == m_Interpolaters::end())
				{
					LinearInterpolator<T> interpolator = new LinearInterpolator<T>();
					m_Interpolaters.insert(std::make_pair<unsigned int, LinearInterpolator<T>*>(properid, interpolator));
					return interpolator;
				}
				return *result;
			}
			std::map<unsigned int, LinearInterpolator<T>*> m_Interpolaters;
		};
	}
}