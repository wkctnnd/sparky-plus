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
			template<class T>
			T* AddComponent()
			{
				T* comp = new T();
				m_Components.push_back(T);
				return comp;
			}
			void Attach(Component* component);
			void Attach(Actor* actor);
			TransformComponent* GetTransform() { return (TransformComponent*)m_Components[0]; }
			int GetComponentCount() { return m_Components.size(); }
			Component* GetComponent(int i) { return m_Components[i]; }
			template<class T>
			std::vector<T*> GetChildrenComponents();
		private:
			//0号元素默认为transform组件，所以m_components的size>=1
			std::vector<Component*> m_Components;
		};
	}
}
