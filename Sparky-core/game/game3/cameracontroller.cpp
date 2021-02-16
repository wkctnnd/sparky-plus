#include "cameracontroller.h"
#include "input/input.h"
#include "world/component/controller.h"
#include "world/component/transformcomponent.h"
#include "world/component/animationcomponent.h"
#include "world/actor.h"
//#include "movementcomponent.h"
using namespace sparky::animation;
using namespace sparky::input;
using namespace sparky::world;
namespace sparky
{
	namespace game
	{




			void CameraController::MoveUp()
			{
				float3 direction = m_Owner->GetOwner()->GetTransform()->Forward();
				m_Owner->GetOwner()->GetTransform()->Translate(direction*m_Speed);
				//m_Owner->GetOwner()->GetTransform()->Translate(float3(0, 0, m_Speed));
			}


			void CameraController::MoveDown()
			{
				float3 direction = m_Owner->GetOwner()->GetTransform()->Forward();
				m_Owner->GetOwner()->GetTransform()->Translate(direction*-m_Speed);
			}

			void CameraController::MoveLeft()
			{
				float3 direction = m_Owner->GetOwner()->GetTransform()->Right();
				m_Owner->GetOwner()->GetTransform()->Translate(direction*m_Speed);
			}

			void CameraController::MoveRotate(float EulerX, float EulerY, float EulerZ)
			{
				m_Owner->GetOwner()->GetTransform()->RotateYAxis(EulerY);

			}

			void CameraController::MoveRight()
			{
				float3 direction = m_Owner->GetOwner()->GetTransform()->Right();
				m_Owner->GetOwner()->GetTransform()->Translate(direction*-m_Speed);
			}

			void CameraController::SetDirection(float3 direction)
			{
				m_Direction = direction;
			}

			void CameraController::SetSpeed(float speed)
			{
				m_Speed = speed;
			}

			float3 CameraController::GetDirection()
			{
				return m_Direction;
			}

			void CameraController::Update()
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
