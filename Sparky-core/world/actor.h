#pragma once
#include <vector>
#include "world/component/transformcomponent.h"
#include "world/component/staticmeshrenderercomponent.h"
namespace sparky
{
	namespace world
	{
		class Component;
		 
		class Scene;
		class Actor
		{

		public:
			template<class T>
			T* AddComponent()
			{
				T* comp = new T(this);
				m_Components.push_back(comp);
				return comp;
			}
			Actor();
			void Attach(Component* component);
			void Attach(Actor* actor);
			TransformComponent* GetTransform() { return (TransformComponent*)m_Components[0]; }
			int GetComponentCount() { return m_Components.size(); }
			Component* GetComponent(int i) { return m_Components[i]; }

			template<class T>
			Component* GetComponent();
			template<class T>
			std::vector<T*> GetChildrenComponents();

			void AddToScene(Scene* scene);
			void SetActive(bool ac)
			{
				m_IsActive = ac;
			}
			bool IsActive() { return m_IsActive; }
			virtual void Update() ;
			virtual void PreUpdate() {};
			virtual void PostUpdate() {};
		private:
			//0号元素默认为transform组件，所以m_components的size>=1
			std::vector<Component*> m_Components;
			bool m_IsActive;
		};

	



		template<class T>
		Component* Actor::GetComponent()
		{
			 
			for (int i = 0; i < m_Components.size(); i++)
			{
				if (m_Components[i]->GetType() == T::TYPE)
				{
					return m_Components[i];
				}
			}
			
			return 0;
		}


		template<class T>
		std::vector<T*> Actor::GetChildrenComponents()
		{
			std::vector<T*> result;
			for (int i = 0; i < m_Components.size(); i++)
			{
				if (m_Components[i]->GetType() == T::TYPE)
				{
					result.push_back((T*)m_Components[i]);
				}
			}
			TransformComponent* trans = GetTransform();

			for (int i = 0; i < trans->GetChildCount(); i++)
			{
				std::vector<T*> temp = trans->GetChild(i)->GetOwner()->GetChildrenComponents<T>();
				//result.resize(result.size() + temp.size());
				for (int j = 0; j < temp.size(); j++)
				{
					result.push_back(temp[j]);
				}


			}



			return result;

		}
	}
}
