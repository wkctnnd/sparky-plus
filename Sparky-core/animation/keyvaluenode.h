#pragma once
#include <vector>
#include <map>
#include <string>
#include "keyvalue.h"
#include "Interpolator.h"
//https://ppx209.com/videos/33278/av-fc2ppv-1202738/

namespace sparky
{
	namespace animation
	{


		enum ComponentType
		{
			Component_X,
			Component_Y,
			Component_Z,
			Component_W
		};

		template<class T>
		class Property;

		class KeyValueNodeBase
		{
		public:
			KeyValueNodeBase(PropertyType type) { m_Type = type; m_AttachCount = 0; }
			PropertyType GetType() { return m_Type; }
		protected:
			PropertyType m_Type;

		public:
			
			int m_AttachCount; //debug use
			std::vector<std::string>  m_PropertyNames; //debug use
			std::vector<unsigned int>  m_PropertyIDs; //debug use
		};


		//实体与channel发生关系
		template<class T>
		class KeyValueNode :public KeyValueNodeBase
		{
		public:
			KeyValueNode(PropertyType type) :KeyValueNodeBase(type) { m_LastTime = 0; }
			KeyValueNode(KeyValueNode<T>& other) :KeyValueNodeBase(other.GetType())
			{
				m_LastTime = 0;
				m_KeyValueCollectionMap = other.m_KeyValueCollectionMap;
				m_PropertyId = other.m_PropertyId;
			}

			T Evaluate(unsigned long elapse);

			void AddComponent(std::string CurveComponent, class KeyValueCollection*);

			KeyValueNode<T> *CreateKeyValueNode();
		private:

			std::map<std::string, class KeyValueCollection*> m_KeyValueCollectionMap;
			Property<T>* m_Property;
			std::vector<class InterpolatorBase *> m_Interpolators;


			//当动画应用到某个具体entity时，与对应id或名字的property关联
			unsigned int m_PropertyId;
			float m_LastTime;
			//std::vector<>
		};


		//暂时只支持四元数的线性插值，未来增加球形插值
		template<class T>
		T KeyValueNode<T>::Evaluate(unsigned long elapse)
		{
				T value;
				m_LastTime += elapse;
				float temp = 0;
				for (int i = 0; i < m_Interpolators.size(); i++)
				{
					temp = m_Interpolators[i]->Evaluate(m_LastTime);
					value.SetElement(i, temp);
				}

				value.NormalizeSelf();

				return value;
			
			
		}

		template<class T>
		KeyValueNode<T>* KeyValueNode<T>::CreateKeyValueNode()
		{
			KeyValueNode<T>* NewValueNode = new KeyValueNode<T>(*this);

			return NewValueNode;
		}



		//默认 x y z w channel是从小到大填满的
		template<class T>
		void KeyValueNode<T>::AddComponent(std::string CurveComponent, class KeyValueCollection* keyvaluecollection)
		{
			m_KeyValueCollectionMap.insert(std::make_pair(CurveComponent, keyvaluecollection));
			//m_Interpolators.insert(std::make_pair(CurveComponent, keyvaluecollection->GetInterpolator(keyvaluecollection)));
			if(CurveComponent.compare("Component_X")==0)
			{
				if (m_Interpolators.size() < 1)  m_Interpolators.resize(1);
				m_Interpolators[Component_X] = keyvaluecollection->GetInterpolator(keyvaluecollection);
			}

			if (CurveComponent.compare("Component_Y") == 0)
			{
				if (m_Interpolators.size() < 2)  m_Interpolators.resize(2);
				m_Interpolators[Component_Y] = keyvaluecollection->GetInterpolator(keyvaluecollection);
			}

			if (CurveComponent.compare("Component_Z") == 0)
			{			 
				if (m_Interpolators.size() < 3)  m_Interpolators.resize(3);
				m_Interpolators[Component_Z] = keyvaluecollection->GetInterpolator(keyvaluecollection);
			}

			if (CurveComponent.compare("Component_W")==0)
			{
				if (m_Interpolators.size() < 4)  m_Interpolators.resize(4);
				m_Interpolators[Component_W] = keyvaluecollection->GetInterpolator(keyvaluecollection);
			}
			
		}
	}
}
