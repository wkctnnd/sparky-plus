#pragma once

//https://zhuanlan.zhihu.com/p/106946506
#include <vector>
using namespace std;
namespace sparky
{
	namespace world
	{
		class Actor;

		class Component
		{
		public:
			void AttachTo();
			Actor* GetOwner() 
			{
				return m_Owner;
			}
			//Component GetParentComponent();
		protected:
			//std::vector<Component*> m_Children;
			Actor* m_Owner;
			
		};
	}
}