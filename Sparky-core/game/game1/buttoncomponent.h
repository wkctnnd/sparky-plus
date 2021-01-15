
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
		class ButtonComponent :public ScriptComponent
		{
		public:
			ButtonComponent(class Actor* Owner) :ScriptComponent(Owner)
			{
				timeframe = 100;
			}
			void SetDoor(class Actor* leftdoor, class Actor* rightdoor, class Actor* player)
			{
				m_LeftDoor = leftdoor;
				m_RightDoor = rightdoor;
				m_Player = player;
			}
			void PreUpdate();
			void Update();
			void PostUpdate();

			void OnCollided(std::vector<phyx::HitPointInfo>& hitpointinfos);
		private:
			int m_FronzonTime;
			Actor* m_LeftDoor;
			Actor* m_RightDoor;
			Actor* m_Player;
			bool IsOpen;
			int timeframe;
		};
	}


}


