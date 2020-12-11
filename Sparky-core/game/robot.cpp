#pragma once
#include "robotcomponent.h"
 

using namespace sparky::world;

namespace sparky
{
	namespace game
	{
		class Robot :public Actor
		{
		public:
			Robot(class Scene* scene, class RawMesh* MeshResourc)
			{
				m_MeshComponent = AddComponent<StaticMeshRendererComponent>();
				m_RigidBodyComponent = AddComponent<RigidBodyComponent>();
				m_RobotComponent = AddComponent<RobotComponent>();
				m_MeshComponent->AddStaticMesh(MeshResourc);
				scene->AddActor(this);
			}

			void PreUpdate();
			void Update();
			void PostUpdate();

			void SetController(class Controller* controller);
		private:
			//class RawMesh* m_MeshResource;
			StaticMeshRendererComponent* m_MeshComponent;
			RigidBodyComponent* m_RigidBodyComponent;
			RobotComponent* m_RobotComponent;
			//MovementComponent* m_MoveComponent;
		};
	}


}


