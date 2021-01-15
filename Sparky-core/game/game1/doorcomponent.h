
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
		class DoorComponent :public ScriptComponent
		{
		public:
			DoorComponent(class Actor* Owner):ScriptComponent(Owner)
			{
				
			}

			void PreUpdate();
			void Update();
			void PostUpdate();

			void OnCollided(std::vector<phyx::HitPointInfo>& hitpointinfos) {};
		private:
			int m_FronzonTime;
		};
	}


}


