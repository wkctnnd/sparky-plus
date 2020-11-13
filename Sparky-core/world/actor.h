#pragma once
#include <vector>

namespace sparky
{
	namespace world
	{
		class Component;
		class Actor
		{

		public:
			void Attach(Component* component);

		private:
			std::vector<Component*> m_Components;
		};
	}
}
