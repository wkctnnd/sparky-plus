#include "actor.h"
#include "scene.h"
#include "component/transformcomponent.h"
namespace sparky
{
	namespace world
	{
		void Actor::Attach(Actor* actor)
		{
			TransformComponent* trans = (TransformComponent*)m_Components[0];
			TransformComponent* trans2 = (TransformComponent*)actor->GetComponent(0);
			trans->AttachTo(*trans2);

		}

		template<class T>
		std::vector<T*> Actor::GetChildrenComponents()
		{
			std::vector<T*> result;
			for (int i = 0; i < m_Components.size(); i++)
			{
				if (m_Components[i]->GetType() == T::TYPE)
				{
					result.push_back(m_Components[i]);
				}
			}
			TransformComponent* trans = GetTransform();

			for (int i = 0; i < trans->GetChildCount(); i++)
			{
				std::vector<T*> temp = result.trans->GetChild(i)->GetOwner()->GetChildrenComponents();
				result.resize(result.size() + temp.size());
				for (int j = 0; j < temp.size(); j++)
				{
					result.push_back(temp[j]);
				}


			}



			return result;

		}


	}
}