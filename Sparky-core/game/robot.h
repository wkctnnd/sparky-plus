#pragma once
 
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
#include "robotcomponent.h"
//#include "movementcomponent.h"

using namespace sparky::world;

namespace sparky
{
	namespace animation
	{
		class AnimationComponent;
	}
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

		private:
			//class RawMesh* m_MeshResource;
			StaticMeshRendererComponent* m_MeshComponent;
			RigidBodyComponent* m_RigidBodyComponent;
			RobotComponent* m_RobotComponent;
			animation::AnimationComponent* m_AnimationComponent;
		};
	}


}


