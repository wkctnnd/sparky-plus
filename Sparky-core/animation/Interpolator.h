#pragma once
#include <string>
#include <map>
namespace sparky
{
	namespace animation
	{

		template< class datatype>
		class Property;

		enum InterpolatorType
		{
			Linear_Type,
			TypeNum
		};

		class InterpolatorBase
		{
		public:
			virtual void Evaluate(unsigned long duration) = 0;
		};

		template<class T>
		class Interpolator:InterpolatorBase
		{
		public:
		 
			Interpolator(Property<T>* property)
			{
				m_Property = property;
			}
			 
			void Evaluate(unsigned long duration)
			{
	 
			}

			/*template<class T>
			static InterpolatorType<T> *GetInterpolator(unsigned int propertyid,InterpolatorType type)
			{
				switch (type)
				{
				case sparky::animation::Linear_Type:
					return LinearInterpolator<T>::GetInterpolator(propertyid);
 
				 
				default:
					break;
				}
			}*/
		protected:
			 
			Property<T>* m_Property;
			unsigned int m_LastFrame;
		};

		template<class T>
		class LinearInterpolator :public Interpolator<T>
		{
		public:
			LinearInterpolator(Property<T>* property):Interpolator<T>(property)
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
			std::map<unsigned int, LinearInterpolator<T>*> m_Interpolaters;
		};
	}
}