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

			Interpolator<datatype>* GetInterpolator(Property<datatype>* property);

				// T& Evaluate(unsigned long time);
				void SetInterpolatorType(InterpolatorType type);

				void AddKeyValue(KeyValue<datatype>& keyvalue);
			
			 datatype Get() { return m_Value; }
			// void BindData(KeyValueSet<datatype>*  data);

		private:
			std::vector<KeyValue<datatype>>  m_KeyValues;
			InterpolatorType  m_Type;
			datatype m_Value;
		};

		/*template< class datatype>
		void sparky::animation::Property<datatype>::AddKeyValue(KeyValue<datatype>& keyvalue)
		{
		
		}
		
		template< class datatype>
		void sparky::animation::Property<datatype>::SetInterpolatorType(InterpolatorType type)
		{
		
		}
		
		template< class datatype>
		sparky::animation::Interpolator<datatype>* sparky::animation::Property<datatype>::GetInterpolator(Property<datatype>* property)
		{
		return nullptr;
		}*/
		

	}
}
#include "property.inl"
