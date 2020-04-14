#pragma once
#include <string>
#include <vector>
#include "Interpolator.h"
namespace sparky
{
	namespace animation
	{

		template< class datatpe, typename InterpType, InterpType type>
		class Property
		{
 
			 void Set
			 T& Evaluate();

		private:
			KeyValueSet<datatype>* m_ValueSet;
			unsigned int m_CurrentKeyLocation;
			InterpolatorType m_type;
		};



	}
}
#include "property.cpp"
