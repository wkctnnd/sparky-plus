#pragma once
#include <string>
#include <vector>
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
		
		//struct KeyLocation
		//{

		//};
		template<class T>
		class KeyValueSet
		{
			friend class LinearInterpolator <T>;
			void AddKeyValue(KeyValue<T>& keyvalue);
			virtual T& Evaluate();

		private:
			std::vector<KeyValue<T>>  m_KeyValues;
			
		};


	}
}