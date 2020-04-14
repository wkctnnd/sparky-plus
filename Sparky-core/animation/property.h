#pragma once
#include <string>
#include <vector>
#include "Interpolator.h"
namespace sparky
{
	namespace animation
	{
		template<class T>
		struct KeyValue
		{
			unsigned int time;//millisecond
			T value;
		};

		template< class datatype>
		class Property
		{
		public:
			Interpolator<datatype>* GetInterpolator();
			 T& Evaluate(unsigned long time);
			 void SetInterpolatorType(InterpolatorType type)
			 void AddKeyValue(KeyValue<T>& keyvalue);
			 datatype Get() { return m_Value; }
			// void BindData(KeyValueSet<datatype>*  data);

		private:
			std::vector<KeyValue<datatype>>  m_KeyValues;
			InterpolatorType  m_Type;
			datatype m_Value;
		};



	}
}
#include "property.cpp"
