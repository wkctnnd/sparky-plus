#pragma once

//https://zhuanlan.zhihu.com/p/106946506
#include <vector>
using namespace std;
namespace sparky
{
	namespace world
	{
		class Actor;

		enum ComponentType
		{
			CAMER_TYPE,
			TRANSFORM_TYPE
		};
		class Component
		{
		public:
			Actor* GetOwner() 
			{
				return m_Owner;
			}
			virtual ComponentType GetType() = 0;

			//Component GetParentComponent();
		protected:
			//std::vector<Component*> m_Children;
			Actor* m_Owner;
			
		};
	}
}