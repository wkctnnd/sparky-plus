#pragma once
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
#include "Playercomponent.h"
using namespace sparky::world;

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
				m_MeshComponent->AddStaticMesh(MeshResourc);
				scene->AddActor(this);
			}

			void SetController(class Controller* controller)
			void PreUpdate();
			void Update();
			void PostUpdate();


		private:
			//class RawMesh* m_MeshResource;
			StaticMeshRendererComponent* m_MeshComponent;
			RigidBodyComponent* m_RigidBodyComponent;
			PlayerComponent* m_PlayerComponent;
		};
	}


}


