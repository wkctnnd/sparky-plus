#pragma once
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/component.h"
using namespace sparky::world;

namespace sparky
{
	namespace game
	{
		class PlayerComponent :public Component
		{
		public:
			PlayerComponent(Actor *owner):Component(owner)
			{

			}



		private:

		};
	}


}


