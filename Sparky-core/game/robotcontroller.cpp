#include "robotcontroller.h"
#include "input/input.h"
#include "robot.h"
//#include "movementcomponent.h"
#include "utils/random.h"
#include "world/actor.h"
#include "world/component/animationcomponent.h"
#include "utils/timer.h"
#include "engine.h"
using namespace sparky::input;
namespace sparky
{
	namespace game
	{

		void RobotController::Update()
		{
			Robot* robot = (Robot*)(m_Owner);
			//MovementComponent *comp = (MovementComponent *)robot->GetComponent<MovementComponent>();
			m_Speed = 0.01;
			m_Owner->GetOwner()->GetTransform()->Translate(m_Direction * m_Speed);
			/*RigidBodyComponent* rigidbody = player->GetComponent<RigidBodyComponent>();*/

		}

		float3 RobotController::GetRandomDirection()
		{
			float num[3];
			Random randomengine;
			randomengine.Seed(Engine::GlobalTimer.GetElapsemillionseconds());
			randomengine.GenerateRandomNumber(num, 3, 2, 0);
			float3 temp(num[0], 0, num[2]);
			temp = (temp - float3(1,0,1)) / 2.0f;
			return temp.NormalizeSelf();
		}





		void RobotController::MoveUp()
		{
			m_Owner->GetOwner()->GetTransform()->Translate(float3(0, 0, m_Speed));
		}


		void RobotController::MoveDown()
		{
			m_Owner->GetOwner()->GetTransform()->Translate(float3(0, 0, -m_Speed));
		}

		void RobotController::MoveLeft()
		{
			m_Owner->GetOwner()->GetTransform()->Translate(float3(-m_Speed, 0, 0));
		}


		void RobotController::MoveRight()
		{
			m_Owner->GetOwner()->GetTransform()->Translate(float3(m_Speed, 0, 0));
		}

		void RobotController::SetDirection(float3 direction)
		{
			m_Direction = direction;
		}

		void RobotController::SetSpeed(float speed)
		{
			m_Speed = speed;
		}

		float3 RobotController::GetDirection()
		{
			return m_Direction;
		}
	};
}
