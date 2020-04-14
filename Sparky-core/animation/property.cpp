#include "property.h"

namespace sparky
{
	namespace animation
	{
		template< class datatype>
		Interpolator<datatype>* Property<datatype>::GetInterpolator()
		{
			InterpolatorType<datatype>* interpolator = new InterpolatorType<datatype>();
			return interpolator;
		}

		template< class datatype>
		void Property<datatype>::SetInterpolatorType(InterpolatorType type)
		{
			m_Type = type;
		}
	}
}



