#include "Robotcomponent.h"
#include "input/input.h"
#include "controller.h"
#include "robot.h"
using namespace sparky::input;
namespace sparky
{
	namespace game
	{
		class RobotController :public Controller
		{
		public:
			void Update()
			{
				Robot* robot = (Robot*)m_Owner;
				MovementComponent *comp = (MovementComponent*)robot->GetComponent<MovementComponent>();
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

				RigidBodyComponent* rigidbody = (RigidBodyComponent*)robot->GetComponent<RigidBodyComponent>();

			}

			void SetOwner(Actor*);

		private:

		};
	}
}
