#pragma once
#include <vector>

namespace sparky
{
	namespace world
	{
		class Component;
		class TransformComponent;
		class Scene;
		class Actor
		{

		public:
			void Attach(Component* component);
			void Attach(Actor* actor);
			TransformComponent* GetTransform() { return (TransformComponent*)m_Components[0]; }
		private:
			//0��Ԫ��Ĭ��Ϊtransform���������m_components��size>=1
			std::vector<Component*> m_Components;
		};
	}
}
