#pragma once
 
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
 
#include "render/rendermaterial.h"
#include "world/component/animationcomponent.h"
//#include "movementcomponent.h"
#include "utils/random.h"
 
#include "DoorComponent.h"
using namespace sparky::world;
using namespace sparky::render;
namespace sparky
{
 
	namespace game
	{
		class Door :public Actor
		{
		public:
			Door(class Scene* scene, class RawMesh* MeshResourc):Actor("Door")
			{
				m_MeshComponent = AddComponent<StaticMeshRendererComponent>();
				m_RigidBodyComponent = AddComponent<RigidBodyComponent>();
				
				m_DoorComponent = AddComponent<DoorComponent>();
				m_MeshComponent->AddStaticMesh(MeshResourc);
				m_RigidBodyComponent->GenerateShape(MeshResourc, phyx::ShapeType::AABB_Shape);
				//m_AnimationComponent = AddComponent<AnimationComponent>();
				//RobotController* robotcontroller = new RobotController();
				//m_AnimationComponent->SetController(robotcontroller);
				//m_RandomEngine.Seed(2);
				scene->AddActor(this);
			 
			}
			 
		/*	void PreUpdate();
			void Update();
			void PostUpdate();*/

		private:
			//class RawMesh* m_MeshResource;
			StaticMeshRendererComponent* m_MeshComponent;
			RigidBodyComponent* m_RigidBodyComponent;
			DoorComponent* m_DoorComponent;
			//world::AnimationComponent* m_AnimationComponent;
			/*float3 DiffuseColor;*/
			
			float  m_Life;
		private:
			
		};
	}


}


