#pragma once
#include <vector>
#include <map>
#include <string>
 
//https://ppx209.com/videos/33278/av-fc2ppv-1202738/
//#define Curve_Component_X "X"
//#define Curve_Component_Y "Y"
//#define Curve_Component_Z "Z"
namespace sparky
{
	namespace animation
	{
		enum KeyValueNodeType
		{
			Translate_Type,
			Scale_Type,
			Rotation_Type,

		};
		
		enum ComponentType
		{
			Component_X,
			Component_Y,
			Component_Z
		};

		template<class T>
		class Property;

		//实体与channel发生关系
		template<class T>
		class KeyValueNode
		{
		public:
			KeyValueNode(KeyValueNodeType type) :m_Type(type) {}
			KeyValueNode(KeyValueNode<T>& other)
			{
				m_Type = other.m_Type;
				m_KeyValueCollectionMap = other.m_KeyValueCollectionMap;
				m_PropertyId = other.m_PropertyId;
			}
			KeyValueNodeType GetType() { return m_Type; }
			T Evaluate();
			
			void AddComponent(const char* CurveComponent, class KeyValueCollection*);

			KeyValueNode<T> *CreateKeyValueNode();
		private:
			KeyValueNodeType m_Type;
			std::map<std::string, class KeyValueCollection*> m_KeyValueCollectionMap;
			Property<T>* m_Property;
			std::vector<InterpolatorBase *> m_Interpolators;


			//当动画应用到某个具体entity时，与对应id或名字的property关联
			unsigned int m_PropertyId;
			//std::vector<>
		};

		template<class T>
		T KeyValueNode<T>::Evaluate()
		{
			T value;
			for(int i=0;i<m_Interpolators.size();i++)
				m_Interpolators[i]->Evaluate();
			return value;
		}

		template<class T>
		KeyValueNode<T>* KeyValueNode<T>:: CreateKeyValueNode()
		{
			KeyValueNode<T>* NewValueNode = new KeyValueNode<T>(*this);
		
			return NewValueNode;
		}

		template<class T>
		void KeyValueNode<T>::AddComponent(const char* CurveComponent, class KeyValueCollection* keyvaluecollection)
		{
			m_KeyValueCollectionMap.insert(CurveComponent, keyvaluecollection);
		}
	}
}
