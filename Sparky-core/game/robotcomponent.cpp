
#include "robotcomponent.h"
#include "world/component/animationcomponent.h"
#include "robotcontroller.h"
using namespace sparky::world;

namespace sparky
{
	namespace game
	{


		void RobotComponent::PreUpdate()
		{
		}
		void RobotComponent::Update()
		{

		}
		void RobotComponent::PostUpdate()
		{

		}

		void RobotComponent::OnCollided()
		{
			AnimationComponent *animcomp = (AnimationComponent *)m_Owner->GetComponent<AnimationComponent>();
			RobotController* con = (RobotController*)animcomp->GetController();
			con->SetDirection(con->GetDirection()*-1);
		}



	}


}

