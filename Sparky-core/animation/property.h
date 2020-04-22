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

			void BindKeyValueNode(class KeyValueNodeBase* keyvaluenode);
			//���propterty�õ�ǰֵ��proptery��Ӧ���keyvaluenode��ͨ��Ȩ�ػ��
			datatype EvaluateValue(unsigned long time);

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
		datatype Property<datatype>::EvaluateValue(unsigned long time)
		{
			datatype result;
			for (int i = 0; i < m_KeyValueNodeArray.size(); i++)
			{
				result += ((KeyValueNode<datatype>*)(m_KeyValueNodeArray[i]))->Evaluate(time) * m_WeightArray[i];
			}

			return result;
		}

		template<class datatype>
		void Property<datatype>::BindKeyValueNode(class KeyValueNodeBase* keyvaluenode)
		{
			m_KeyValueNodeArray.push_back(keyvaluenode);
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