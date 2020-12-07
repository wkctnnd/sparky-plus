#pragma once
#pragma once
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
 
using namespace sparky::world;

namespace sparky
{
	namespace game
	{
		class RobotComponent :public Component
		{
		public:
			RobotComponent(class Actor* Owner):Component(Owner)
			{
 
			}

			void PreUpdate();
			void Update();
			void PostUpdate();


		private:
	 
		};
	}


}


