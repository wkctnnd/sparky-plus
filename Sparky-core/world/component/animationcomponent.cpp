#pragma once
#include "animationcomponent.h"
namespace sparky
{
	namespace world
	{

			ComponentType AnimationComponent::TYPE = ANIMATION_TYPE;

			void AnimationComponent::Update()
			{
				m_Controller->Update();

			}
 
	
	}
}
