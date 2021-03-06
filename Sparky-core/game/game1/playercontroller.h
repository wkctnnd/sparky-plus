#pragma once
#include "animation/controller.h"
#include "maths/vec3.h"
using namespace sparky::maths;
using namespace sparky::animation;
namespace sparky
{
	namespace world
	{
		class AnimationComponent;
	}
	namespace game
	{
		class PlayerController :public Controller
		{
		public:
			PlayerController() :m_Speed(0.1f) { m_MouseMode = 0; }

			virtual void Update();

			void MoveUp();


			void MoveDown();

			void MoveLeft();

			void MoveRotate(float EulerX, float EulerY, float EulerZ);

			void MoveRight();

			void SetDirection(float3 direction);

			void SetSpeed(float speed);

			float3 GetDirection();

	 
		private:

			float3 m_Direction;
			float m_Speed;
			int m_PrevX;
			int m_PrevY;

			int m_MouseMode;
		};
	}
}