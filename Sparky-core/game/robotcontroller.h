#pragma once

#include "animation/controller.h"
#include "utils/random.h"
using namespace sparky::animation;
namespace sparky
{
	namespace game
	{
		class RobotController :public Controller
		{
		public:
			RobotController()
			{
				m_Direction = GetRandomDirection();
			}
			virtual void Update();

			void MoveUp();


			void MoveDown();

			void MoveLeft();


			void MoveRight();

			void SetDirection(float3 direction);

			void SetSpeed(float speed);

			float3 GetDirection();

 
		private:
			float3 GetRandomDirection();
			

			float3 m_Direction;
			float m_Speed;
		};
	}
}