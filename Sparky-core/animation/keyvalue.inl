
namespace sparky
{
	namespace animation
	{
		/*template< class datatype>
		Interpolator<datatype>* KeyValueCollection<datatype>::GetInterpolator(KeyValueCollection<datatype>* property)
		{
			Interpolator<datatype>* interpolator = nullptr;
			switch (m_Type)
			{
			case Linear_Type:
			{
				interpolator = new LinearInterpolator< datatype >(property);
			}
			}

			return interpolator;
		}*/

		void KeyValueCollection::SetInterpolatorType(InterpolatorType type)
		{
			m_Type = type;
		}


		void KeyValueCollection::AddKeyValue(KeyValue& keyvalue)
		{
			m_KeyValues.push_back(keyvalue);
		}


		KeyValueCollection* KeyValueCollection::GetInterpolator(KeyValueCollection* values)
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

