#pragma once
#include <vector>
#include <map>
#include <string>
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
			Component_Z
		};

		template<class T>
		class Property;

		class KeyValueNodeBase
		{

		};


		//实体与channel发生关系
		template<class T>
		class KeyValueNode:public KeyValueNodeBase
		{
		public:
			KeyValueNode(PropertyType type) :m_Type(type) {}
			KeyValueNode(KeyValueNode<T>& other)
			{
				m_Type = other.m_Type;
				m_KeyValueCollectionMap = other.m_KeyValueCollectionMap;
				m_PropertyId = other.m_PropertyId;
			}
			PropertyType GetType() { return m_Type; }
			T Evaluate(unsigned long elapse);
			
			void AddComponent(std::string CurveComponent, class KeyValueCollection*);

			KeyValueNode<T> *CreateKeyValueNode();
		private:
			PropertyType m_Type;
			std::map<std::string, class KeyValueCollection*> m_KeyValueCollectionMap;
			Property<T>* m_Property;
			std::vector<class InterpolatorBase *> m_Interpolators;


			//当动画应用到某个具体entity时，与对应id或名字的property关联
			unsigned int m_PropertyId;
			//std::vector<>
		};

		template<class T>
		T KeyValueNode<T>::Evaluate(unsigned long elapse)
		{
			T value;
			for(int i=0;i<m_Interpolators.size();i++)
				m_Interpolators[i]->Evaluate(elapse);
			return value;
		}

		template<class T>
		KeyValueNode<T>* KeyValueNode<T>:: CreateKeyValueNode()
		{
			KeyValueNode<T>* NewValueNode = new KeyValueNode<T>(*this);
		
			return NewValueNode;
		}

		template<class T>
		void KeyValueNode<T>::AddComponent(std::string CurveComponent, class KeyValueCollection* keyvaluecollection)
		{
			m_KeyValueCollectionMap.insert(std::make_pair(CurveComponent, keyvaluecollection));
		}
	}
}
