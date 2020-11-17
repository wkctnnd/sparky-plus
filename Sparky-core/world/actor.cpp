#include "actor.h"
#include "scene.h"
namespace sparky
{
	namespace world
	{
		void Actor::Attach(Actor* actor)
		{
			Scene::GetCurrentScene()->
			actor->m_Components[0]->AttachTo(this->m_Components[0])
			
		}
	}
}