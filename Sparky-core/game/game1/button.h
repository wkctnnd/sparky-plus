#pragma once
 
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"

#include "render/rendermaterial.h"
#include "world/component/animationcomponent.h"
//#include "movementcomponent.h"
#include "utils/random.h"

#include "buttoncomponent.h"
using namespace sparky::world;
using namespace sparky::render;
namespace sparky
{
 
	namespace game
	{
		class Button :public Actor
		{
		public:
			Button(class Scene* scene, class RawMesh* MeshResourc, Actor* leftdoor, Actor* rightdoor, Actor* player):Actor("Button")
			{
				m_MeshComponent = AddComponent<StaticMeshRendererComponent>();
				m_RigidBodyComponent = AddComponent<RigidBodyComponent>();
				
				m_Button = AddComponent<ButtonComponent>();
				m_Button->SetDoor(leftdoor, rightdoor, player);
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
			ButtonComponent* m_Button;
			//world::AnimationComponent* m_AnimationComponent;
			/*float3 DiffuseColor;*/
			
			float  m_Life;
			Actor *m_Door;
		private:
			
		};
	}


}


