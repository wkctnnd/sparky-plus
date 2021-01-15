#pragma once
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
//#include "movementcomponent.h"
#include "Playercomponent.h"
#include "render/rendermaterial.h"
#include "world/component/animationcomponent.h"
#include "game/game1/playercontroller.h"
using namespace sparky::world;
using namespace sparky::render;
namespace sparky
{
	namespace asset
	{
		class RawMesh;
	}
	namespace game
	{
		class Player :public Actor
		{
		public:
			Player(class Scene* scene, asset::RawMesh* fullres, asset::RawMesh* bodyres, asset::RawMesh* leftarmres, asset::RawMesh* rightarmres, bool AsOne = true):Actor("Player")
			{
				m_PartAsOne = AsOne;
				if (m_PartAsOne == true)
				{
					m_MeshComponent = AddComponent<StaticMeshRendererComponent>();
					m_RigidBodyComponent = AddComponent<RigidBodyComponent>();

					m_PlayerComponent = AddComponent<PlayerComponent>();
					
					m_MeshComponent->AddStaticMesh(fullres);
					m_RigidBodyComponent->GenerateShape(fullres, phyx::ShapeType::Sphere_Shape);
				}

				else
				{
					m_MeshComponent = AddComponent<StaticMeshRendererComponent>();
					m_RigidBodyComponent = AddComponent<RigidBodyComponent>();

					m_PlayerComponent = AddComponent<PlayerComponent>();

					m_MeshComponent->AddStaticMesh(bodyres);
					m_RigidBodyComponent->GenerateShape(bodyres, phyx::ShapeType::AABB_Shape);

					//×óÊÖ
					m_LeftArm = new Actor();
					StaticMeshRendererComponent* leftarmmeshcomponent = m_LeftArm->AddComponent<StaticMeshRendererComponent>();
					leftarmmeshcomponent->AddStaticMesh(leftarmres);
					RigidBodyComponent* leftarmbodycomponent = m_LeftArm->AddComponent<RigidBodyComponent>();
					leftarmbodycomponent->GenerateShape(leftarmres, phyx::ShapeType::AABB_Shape);
					/*m_LeftArm->Attach(this);*/
					Attach(m_LeftArm);
					//ÓÒÊÖ
					m_RightArm = new Actor();
					StaticMeshRendererComponent* rightarmmeshcomponent = m_RightArm->AddComponent<StaticMeshRendererComponent>();
					rightarmmeshcomponent->AddStaticMesh(rightarmres);
					RigidBodyComponent* rightarmbodycomponent = m_RightArm->AddComponent<RigidBodyComponent>();
					rightarmbodycomponent->GenerateShape(leftarmres, phyx::ShapeType::AABB_Shape);
					//m_RightArm->Attach(this);
					Attach(m_RightArm);

			
				}
				
				m_AnimComponent = AddComponent<AnimationComponent>();
				PlayerController* playercontroller = new PlayerController();
				m_AnimComponent->SetController(playercontroller);
				//GetTransform()->SetLocalPosition(float3(37.0, 0, 35.0));
				//Actor* dummy = scene->AddActor();
		 
				scene->AddActor(this);
			}

		 
			/*void PreUpdate() {};
			void Update() {};
			void PostUpdate() {};*/

		 

		private:
			//class RawMesh* m_MeshResource;
			StaticMeshRendererComponent* m_MeshComponent;
			RigidBodyComponent* m_RigidBodyComponent;
			class PlayerComponent* m_PlayerComponent;
			world::AnimationComponent* m_AnimComponent;

			Actor* m_RightArm;
			Actor* m_LeftArm;

			bool m_PartAsOne;
			/*float3 DiffuseColor;*/
			//class MovementComponent* m_MoveComponent;
		};
	}


}


