#pragma once
#include "component.h"
#include "animation/controller.h"
namespace sparky
{
	namespace animation
	{
		class Controller;
	}
	namespace world
	{
		class AnimationComponent :public Component
		{
		public:
			static ComponentType TYPE;

			AnimationComponent(Actor* owner) :Component(owner) {}
			void SetController(animation::Controller* c)
			{
				m_Controller = c;
				c->SetOwner(this);
			}
			animation::Controller* GetController()
			{
				return m_Controller;
			}
			ComponentType GetType()
			{
				return ComponentType::ANIMATION_TYPE;
			}
			virtual void PreUpdate() {}
 
			virtual void PostUpdate() {}
			void Update();
		private:
			class animation::Controller* m_Controller;
		};
	}
}
