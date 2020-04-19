#pragma once


namespace sparky
{
	namespace animation
	{
		template<class T>
		class KeyValueNode;

		template<class datatype>
		class Property
		{
		public:
			datatype EvaluateValue(unsigned long time);


		private:
			//KeyValueNode<datatype> dta;
			std::vector<KeyValueNode<datatype>*> m_KeyValueNodeArray;
		};


		template<class datatype>
		datatype Property<datatype>::EvaluateValue(unsigned long time)
		{

		}
	}
}