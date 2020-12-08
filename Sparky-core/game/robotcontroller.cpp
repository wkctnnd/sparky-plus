#include "robotcontroller.h"
#include "input/input.h"
#include "robot.h"
#include "movementcomponent.h"
#include "utils/random.h"
using namespace sparky::input;
namespace sparky
{
	namespace game
	{

		void RobotController::Update()
		{
			Robot* robot = (Robot*)(m_Owner);
			MovementComponent *comp = (MovementComponent *)robot->GetComponent<MovementComponent>();
			if (Input::GetKey(KEY_W))
			{
				comp->MoveUp();
			}
			else if (Input::GetKey(KEY_S))
			{
				comp->MoveDown();
			}
			else if (Input::GetKey(KEY_A))
			{
				comp->MoveLeft();
			}
			else if (Input::GetKey(KEY_S))
			{
				comp->MoveRight();
			}

			/*RigidBodyComponent* rigidbody = player->GetComponent<RigidBodyComponent>();*/

		}

		float3 RobotController::GetRandomDirection()
		{
			float num[3];
			m_RandomEngine.GenerateRandomNumber(num, 3, 2, 0);
			float3 temp(num[0], num[1], num[2]);
			temp = (temp - float3(1,1,1)) / 2.0f;
			return temp.NormalizeSelf();
		}



	};
}
}
