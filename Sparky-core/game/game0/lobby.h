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
		class Lobby :public Actor
		{
		public:
			Lobby(class Scene* scene, class asset::RawMesh* MeshResourc, class asset::Material* MaterialResource)
			{
				m_MeshComponent = AddComponent<StaticMeshRendererComponent>();
				m_RigidBodyComponent = AddComponent<RigidBodyComponent>();		 
				m_MeshComponent->AddStaticMesh(MeshResourc);
				m_MeshComponent->AddMaterial( MaterialResource);
				scene->AddActor(this);
			}


			void AddBoxColliderActor();
			/*void PreUpdate() {};
			void Update() {};
			void PostUpdate() {};*/


		private:
			//class RawMesh* m_MeshResource;
			StaticMeshRendererComponent* m_MeshComponent;
			RigidBodyComponent* m_RigidBodyComponent;
			

		private:
			RawMesh GenerateRawMesh(float length,float3 offset);
 
		};
	}


}


