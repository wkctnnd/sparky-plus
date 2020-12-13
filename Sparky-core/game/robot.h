#pragma once
 
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
#include "robotcomponent.h"
#include "render/rendermaterial.h"
#include "world/component/animationcomponent.h"
//#include "movementcomponent.h"
#include "utils/random.h"
#include "robotcontroller.h"
using namespace sparky::world;
using namespace sparky::render;
namespace sparky
{
 
	namespace game
	{
		class Robot :public Actor
		{
		public:
			Robot(class Scene* scene, class RawMesh* MeshResourc, float life)
			{
				m_MeshComponent = AddComponent<StaticMeshRendererComponent>();
				m_RigidBodyComponent = AddComponent<RigidBodyComponent>();
				
				m_RobotComponent = AddComponent<RobotComponent>();
				m_MeshComponent->AddStaticMesh(MeshResourc);
				m_RigidBodyComponent->GenerateShape(MeshResourc, phyx::ShapeType::Sphere_Shape);
				m_AnimationComponent = AddComponent<AnimationComponent>();
				RobotController* robotcontroller = new RobotController();
				m_AnimationComponent->SetController(robotcontroller);
				//m_RandomEngine.Seed(2);
				scene->AddActor(this);
				m_Life = life;
				//DiffuseColor = GetRandomColor();
			}
			void Update()
			{
				if (m_Life !=0)
				{
					Actor::Update();
					m_Life= m_Life-0.01;
				}
				
			}

			float GetLife()
			{
				return  m_Life;
			}
		/*	void PreUpdate();
			void Update();
			void PostUpdate();*/

		private:
			//class RawMesh* m_MeshResource;
			StaticMeshRendererComponent* m_MeshComponent;
			RigidBodyComponent* m_RigidBodyComponent;
			RobotComponent* m_RobotComponent;
			world::AnimationComponent* m_AnimationComponent;
			/*float3 DiffuseColor;*/
			
			float  m_Life;
		private:
			
		};
	}


}


