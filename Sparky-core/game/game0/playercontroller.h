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
			PlayerController() :m_Speed(0.1f){}

			virtual void Update();

			void MoveUp();


			void MoveDown();

			void MoveLeft();


			void MoveRight();

			void SetDirection(float3 direction);

			void SetSpeed(float speed);

			float3 GetDirection();

	 
		private:

			float3 m_Direction;
			float m_Speed;
			
		};
	}
}