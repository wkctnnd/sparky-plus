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

		Actor::Actor()
		{
			m_Components.push_back(new TransformComponent());
		}


	}
}