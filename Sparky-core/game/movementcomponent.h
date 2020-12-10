#pragma once
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/component.h"
using namespace sparky::world;

namespace sparky
{
	namespace game
	{
		class MovementComponent :public Component
		{
		public:
			MovementComponent(Actor *owner):Component(owner)
			{

			}

			ComponentType GetType()
			{
				return ComponentType::CAMER_TYPE;
			}

			void MoveUp()
			{
				m_Owner->GetTransform()->Translate(float3(0,0, m_Speed));
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


