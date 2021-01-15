
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
		class BoxComponent :public ScriptComponent
		{
		public:
			BoxComponent(class Actor* Owner):ScriptComponent(Owner)
			{
			
			}

			void PreUpdate();
			void Update();
			void PostUpdate();
			void SetPosition(float3 position)
			{
				m_Position = position;
			}
			void OnCollided(std::vector<phyx::HitPointInfo>& hitpointinfos);
		private:
			int m_FronzonTime;
			bool m_Final;
			float3 m_Position;
		};
	}


}


