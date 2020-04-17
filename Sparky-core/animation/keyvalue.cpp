#include "keyvalue.h"
namespace sparky
{
	namespace animation
	{

		void KeyValueCollection::SetInterpolatorType(InterpolatorType type)
		{
			m_Type = type;
		}


		void KeyValueCollection::AddKeyValue(KeyValue& keyvalue)
		{
			m_KeyValues.push_back(keyvalue);
		}


		InterpolatorBase* KeyValueCollection::GetInterpolator(KeyValueCollection* values)
		{
			InterpolatorBase* interpolator = nullptr;
			switch (m_Type)
			{
			case Linear_Type:
			{
				interpolator = new LinearInterpolator(values);
			}
			}

			return interpolator;
		}
	}
}

//template< class datatype>
//void sparky::animation::Property<datatype>::AddKeyValue(KeyValue<datatype>& keyvalue)
//{
//
//}
//
//template< class datatype>
//void sparky::animation::Property<datatype>::SetInterpolatorType(InterpolatorType type)
//{
//
//}
//
//template< class datatype>
//sparky::animation::Interpolator<datatype>* sparky::animation::Property<datatype>::GetInterpolator(Property<datatype>* property)
//{
//return nullptr;
//}

