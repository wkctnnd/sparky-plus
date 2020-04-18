#pragma once
#include <vector>
//https://ppx209.com/videos/33278/av-fc2ppv-1202738/
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
	

		//实体与channel发生关系
		template<class T>
		class KeyValueNode
		{
		public:
			KeyValueNode(KeyValueNodeType type) :m_Type(type) {}
			KeyValueNodeType GetType() { return m_Type; }
			T Evaluate();
			
		private:
			KeyValueNodeType m_Type;
			class KeyValueCollection *m_KeyValueCollection;
			class Property<T>* m_Property;
			std::vector<InterpolatorBase *> m_Interpolators;
			//std::vector<>
		};

		template<class T>
		T KeyValueNode<T>::Evaluate()
		{
			m_Interpolator->Evaluate();
		}
	}
}
