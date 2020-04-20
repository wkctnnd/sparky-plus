#pragma once


namespace sparky
{
	namespace animation
	{
		enum PropertyType
		{
			Translate_Property_Type,
			Scale_Property_Type,
			Rotation_Property_Type,

		};

		template<class T>
		class KeyValueNode;

		template<class datatype>
		class Property
		{
		public:
			Property(PropertyType type, std::string name)
			{
				m_PropertyType = type;
				m_PropertyName = name;
			}

			//获得propterty得当前值，proptery对应多个keyvaluenode，通过权重混合
			datatype EvaluateValue(unsigned long time);

			void SetName(std::string name) { m_PropertyName = name; }
			void SetPropertyType(PropertyType type) { m_PropertyType = type; }
		private:
			//KeyValueNode<datatype> dta;
			std::vector<KeyValueNode<datatype>*> m_KeyValueNodeArray;
			std::vector<float> m_WeightArray;
			int m_PropertyId;
			std::string m_PropertyName;

			PropertyType m_PropertyType;
		};



		//获得propterty得当前值，proptery对应多个keyvaluenode，通过权重混合
		template<class datatype>
		datatype Property<datatype>::EvaluateValue(unsigned long time)
		{
			datatype result;
			for (int i = 0; i < m_KeyValueNodeArray.size(); i++)
			{
				result += m_KeyValueNodeArray[i]->Evaluate(time) * m_WeightArray[i];
			}

			return result;
		}



		//template<class PropertyType, PropertyType type>
		//class Property
		//{
		//public:
		//	Property(PropertyType type, std::string name)
		//	{
		//		m_PropertyType = type;
		//		m_PropertyName = name;
		//	}
		//	datatype EvaluateValue(unsigned long time);

		//	void SetPropertyType(PropertyType type) { m_PropertyType = type; }
		//private:
		//	//KeyValueNode<datatype> dta;
		//	std::vector<KeyValueNode<datatype>*> m_KeyValueNodeArray;
		//	int m_PropertyId;
		//	std::string m_PropertyName;

		//	PropertyType m_PropertyType;
		//};
	}
}