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
				float3 direction = m_Owner->GetOwner()->GetTransform()->Forward();
				m_Owner->GetOwner()->GetTransform()->Translate(direction*m_Speed);
				//m_Owner->GetOwner()->GetTransform()->Translate(float3(0, 0, m_Speed));
			}


			void PlayerController::MoveDown()
			{
				float3 direction = m_Owner->GetOwner()->GetTransform()->Forward();
				m_Owner->GetOwner()->GetTransform()->Translate(direction*-m_Speed);
			}

			void PlayerController::MoveLeft()
			{
				float3 direction = m_Owner->GetOwner()->GetTransform()->Right();
				m_Owner->GetOwner()->GetTransform()->Translate(direction*m_Speed);
			}

			void PlayerController::MoveRotate(float EulerX, float EulerY, float EulerZ)
			{
				m_Owner->GetOwner()->GetTransform()->RotateYAxis(EulerY);

			}

			void PlayerController::MoveRight()
			{
				float3 direction = m_Owner->GetOwner()->GetTransform()->Right();
				m_Owner->GetOwner()->GetTransform()->Translate(direction*-m_Speed);
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
				if (InputManager::GetKey(KEY_W))
				{
					MoveDown();
				}
				if (InputManager::GetKey(KEY_S))
				{
					MoveUp();
				}
				if (InputManager::GetKey(KEY_A))
				{
					MoveRight();
				}

				if (InputManager::GetKey(KEY_D))
				{
					MoveLeft();
				}
				MouseState ms = InputManager::GetMouseState();
				if (ms.button == MouseButton::Mouse_Button_Left)
				{
					if (ms.action == MouseAction::Mouse_Press)
					{
						if (m_MouseMode == 0)
						{
							m_MouseMode = 1;
							m_PrevX = ms.x;
							m_PrevY = ms.y;
						}

					
					}
					else
					{
						m_MouseMode = 0;
					}
				}

				if (m_MouseMode == 1)
				{
					int offsetx = ms.x - m_PrevX;
					int offsety = ms.y - m_PrevY;

					
					m_PrevX = ms.x;
					m_PrevY = ms.y;
					float degree = (float)offsetx / 100.0f;
					printf("%f", degree);
					MoveRotate(0, -degree, 0);
				}
			}
		 
	}
}
