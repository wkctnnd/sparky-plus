
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
			if (m_FronzonTime>0)
			{
				m_FronzonTime--;
			}
			else  
			{
				RigidBodyComponent *rigidcomp = (RigidBodyComponent *)m_Owner->GetComponent<RigidBodyComponent>();
				rigidcomp->SetEnable(true);
			}
		 
		}
		void RobotComponent::PostUpdate()
		{

		}

		void RobotComponent::OnCollided()
		{
			AnimationComponent *animcomp = (AnimationComponent *)m_Owner->GetComponent<AnimationComponent>();
			RigidBodyComponent *rigidcomp = (RigidBodyComponent *)m_Owner->GetComponent<RigidBodyComponent>();
			RobotController* con = (RobotController*)animcomp->GetController();
			con->SetDirection(con->GetDirection()*-1);
			rigidcomp->SetEnable(false);
			m_FronzonTime = 400;
			con->Move(0.3);
		}



	}


}

