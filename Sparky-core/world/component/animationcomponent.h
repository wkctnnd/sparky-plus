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

			void SetController(animation::Controller* c)
			{
				m_Controller = c;
			}
			animation::Controller* GetController()
			{
				return m_Controller;
			}
			ComponentType GetType()
			{
				return ComponentType::ANIMATION_TYPE;
			}

		private:
			class animation::Controller* m_Controller;
		};
	}
}
