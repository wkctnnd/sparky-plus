#pragma once
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
#include "world/component/scriptcomponent.h"
using namespace sparky::world;

namespace sparky
{
	namespace game
	{
		class PlayerComponent :public ScriptComponent
		{
		public:
			PlayerComponent(Actor* Owner) :ScriptComponent(Owner)
			{

			}

		private:


		};
	}
}