
namespace sparky
{
	namespace animation
	{
		template< class datatype>
		Interpolator<datatype>* Property<datatype>::GetInterpolator(Property<datatype>* property)
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
		}

		template< class datatype>
		void Property<datatype>::SetInterpolatorType(InterpolatorType type)
		{
			m_Type = type;
		}
		template< class datatype>
		void Property<datatype>::AddKeyValue(KeyValue<datatype>& keyvalue)
		{
			m_KeyValues.push_back(keyvalue);
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

