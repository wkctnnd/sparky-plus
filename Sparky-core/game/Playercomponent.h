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
		class RobotComponent :public ScriptComponent
		{
			void MoveUp()
			{
				m_Owner->GetTransform()->Translate(float3(0, 0, m_Speed));
			}


			void MoveDown()
			{
				m_Owner->GetTransform()->Translate(float3(0, 0, -m_Speed));
			}

			void MoveLeft()
			{
				m_Owner->GetTransform()->Translate(float3(-m_Speed, 0, 0));
			}


			void MoveRight()
			{
				m_Owner->GetTransform()->Translate(float3(m_Speed, 0, 0));
			}

			void SetDirection(float3 direction)
			{
				m_Direction = direction;
			}

			void SetSpeed(float speed)
			{
				m_Speed = speed;
			}

			float3 GetDirection()
			{
				return m_Direction;
			}

		private:

			float3 m_Direction;
			float m_Speed;
		};
	}
}