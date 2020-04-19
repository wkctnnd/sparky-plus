#pragma once
#include <string>
#include <vector>
#include "Interpolator.h"


namespace sparky
{
	namespace animation
	{
 




		struct KeyValue
		{
			KeyValue(float v, unsigned int t)
			{
				value = v;
				time = t;
			}
			unsigned int time;//millisecond
			float value;
		};


		//class KeyValueCollectionBase
		//{
		//public:
		//	virtual InterpolatorBase * GetInterpolator(KeyValueCollectionBase* keyvalues) { return 0; }
		//	int GetUniqueKey() { return m_UniqueKey; }
		//protected:
		//	int m_UniqueKey;
		//};

	
		class KeyValueCollection  
		{
		public:

			//Interpolator<datatype>* GetInterpolator(KeyValueCollection<datatype>* property);

			InterpolatorBase* GetInterpolator(KeyValueCollection* keyvalues);

				// T& Evaluate(unsigned long time);
			void SetInterpolatorType(InterpolatorType type);

			void AddKeyValue(KeyValue& keyvalue);
			
			// float GetValue() { return m_Value; }
			// void BindData(KeyValueSet<datatype>*  data);

		private:
			std::vector<KeyValue>  m_KeyValues;
			InterpolatorType  m_Type;
			//datatype m_Value;
			int m_UniqueKey;
			std::string m_Name;
			
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
//#include "keyvalue.inl"
