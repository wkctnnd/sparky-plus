#include "playercontroller.h"
#include "input/input.h"
#include "player.h"
#include "world/component/transformcomponent.h"
#include "world/component/animationcomponent.h"
//#include "movementcomponent.h"
using namespace sparky::animation;
using namespace sparky::input;
namespace sparky
{
	namespace game
	{




			void PlayerController::MoveUp()
			{
				m_Owner->GetOwner()->GetTransform()->Translate(float3(0, 0, m_Speed));
			}


			void PlayerController::MoveDown()
			{
				m_Owner->GetOwner()->GetTransform()->Translate(float3(0, 0, -m_Speed));
			}

			void PlayerController::MoveLeft()
			{
				m_Owner->GetOwner()->GetTransform()->Translate(float3(m_Speed, 0, 0));
			}


			void PlayerController::MoveRight()
			{
				m_Owner->GetOwner()->GetTransform()->Translate(float3(-m_Speed, 0, 0));
			}

			void PlayerController::SetDirection(float3 direction)
			{
				m_Direction = direction;
			}

			void PlayerController::SetSpeed(float speed)
			{
				m_Speed = speed;
			}

			float3 PlayerController::GetDirection()
			{
				return m_Direction;
			}

			void PlayerController::Update()
			{
				if (Input::GetKey(KEY_W))
				{
					MoveUp();
				}
				if (Input::GetKey(KEY_S))
				{
					MoveDown();
				}
				if (Input::GetKey(KEY_A))
				{
					MoveLeft();
				}

				if (Input::GetKey(KEY_D))
				{
					MoveRight();
				}
			}
		 
	}
}
