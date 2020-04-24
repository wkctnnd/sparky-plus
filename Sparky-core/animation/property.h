#pragma once
#include "global.h"
#include "keyvaluenode.h"
namespace sparky
{
	namespace animation
	{


		//template<class T>
		//class KeyValueNode;

		template<class datatype>
		class Property
		{
		public:
			Property(PropertyType type, std::string name)
			{
				m_PropertyType = type;
				m_PropertyName = name;
			}

			void BindKeyValueNode(class KeyValueNodeBase* keyvaluenode, float weight);
			//���propterty�õ�ǰֵ��proptery��Ӧ���keyvaluenode��ͨ��Ȩ�ػ��
			void EvaluateValue(unsigned long time, datatype& value);

			void SetName(std::string name) { m_PropertyName = name; }
			void SetPropertyType(PropertyType type) { m_PropertyType = type; }

			PropertyType GetType() { return m_PropertyType; }
		private:
			//KeyValueNode<datatype> dta;
			std::vector<KeyValueNodeBase*> m_KeyValueNodeArray;
			std::vector<float> m_WeightArray;
			int m_PropertyId;
			std::string m_PropertyName;

			PropertyType m_PropertyType;
		};



		//���propterty�õ�ǰֵ��proptery��Ӧ���keyvaluenode��ͨ��Ȩ�ػ��
		template<class datatype>
		void Property<datatype>::EvaluateValue(unsigned long time, datatype& value)
		{
			if (m_KeyValueNodeArray.size() != 0)
			{
				datatype result;
				for (int i = 0; i < m_KeyValueNodeArray.size(); i++)
				{
					datatype temp = ((KeyValueNode<datatype>*)(m_KeyValueNodeArray[i]))->Evaluate(time) * m_WeightArray[i];
					result += temp;
				}
				value = result;
			}

		}

		template<class datatype>
		void Property<datatype>::BindKeyValueNode(class KeyValueNodeBase* keyvaluenode, float weight)
		{
			m_KeyValueNodeArray.push_back(keyvaluenode);
			m_WeightArray.push_back(weight);
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