#pragma once
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
//#include "movementcomponent.h"
#include "Playercomponent.h"
#include "render/rendermaterial.h"
#include "world/component/animationcomponent.h"
#include "game/playercontroller.h"
using namespace sparky::world;
using namespace sparky::render;
namespace sparky
{
	namespace game
	{
		class Player :public Actor
		{
		public:
			Player(class Scene* scene, class RawMesh* MeshResourc) 
			{
				m_MeshComponent = AddComponent<StaticMeshRendererComponent>();
				m_RigidBodyComponent = AddComponent<RigidBodyComponent>();
				
				m_PlayerComponent = AddComponent<PlayerComponent> ();
				//m_MoveComponent = AddComponent<MovementComponent>();
				m_MeshComponent->AddStaticMesh(MeshResourc);
				m_RigidBodyComponent->GenerateShape(MeshResourc, m_PlayerComponent, phyx::ShapeType::Sphere_Shape);
				m_AnimComponent = AddComponent<AnimationComponent>();
				PlayerController* playercontroller = new PlayerController();
				m_AnimComponent->SetController(playercontroller);

			/*	StaticMeshRendererComponent *meshrendercom = (StaticMeshRendererComponent*)GetComponent<StaticMeshRendererComponent>();
				RenderMaterial* mat = meshrendercom->GetMaterial(0);
				mat->SetDiffuseColor(float3(1, 0, 0));*/

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
			/*float3 DiffuseColor;*/
			//class MovementComponent* m_MoveComponent;
		};
	}


}


