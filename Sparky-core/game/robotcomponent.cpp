#include "movementcomponent.h"
#include "robotcomponent.h"
using namespace sparky::world;

namespace sparky
{
	namespace game
	{


		void RobotComponent::PreUpdate()
		{

		}

		//�ƶ�������
		void RobotComponent::Update()
		{

		}
		void RobotComponent::PostUpdate()
		{

		}

		void RobotComponent::OnCollided()
		{
			MovementComponent *movecomp = (MovementComponent *)m_Owner->GetComponent<MovementComponent>();
			movecomp->SetDirection(movecomp->GetDirection()*-1);
		}

	}


}

