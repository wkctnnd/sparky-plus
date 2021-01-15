#pragma once
 
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
 
#include "render/rendermaterial.h"
#include "input/input.h"
#include "boxcomponent.h"
using namespace sparky::world;
using namespace sparky::render;
using namespace sparky::input;
namespace sparky
{
 
	namespace game
	{

		class Box :public Actor
		{
		public:
			Box(class Scene* scene, class RawMesh* MeshResourc, class asset::Material* boxmaterial, float3 pos):Actor("Box")
			{
				m_MeshComponent = AddComponent<StaticMeshRendererComponent>();
				m_RigidBodyComponent = AddComponent<RigidBodyComponent>();
				
				m_BoxComponent = AddComponent<BoxComponent>();
				m_BoxComponent->SetPosition(pos);
				m_MeshComponent->AddStaticMesh(MeshResourc);
				m_RigidBodyComponent->GenerateShape(MeshResourc, phyx::ShapeType::Sphere_Shape);
			 
				m_MeshComponent->AddMaterial(boxmaterial);
				scene->AddActor(this);
				m_IsSelect = false;
				m_Scene = scene;
				m_Position = pos;
			}
			void Update()
			{
				if (m_IsSelect ==1 && InputManager::GetKey(KEY_V))
				{
					float3 position = GetTransform()->GetWorldPosition();
					m_Scene->GetRoot()->Attach(this);
					GetTransform()->SetLocalPosition(position);
					Frozon = 100;
					m_IsSelect = 0;
				}
				else if (Frozon > 0)
				{
					Frozon--;

				}
				else if (m_IsSelect==0&&Frozon ==0)
				{
					m_RigidBodyComponent->SetEnable(true);
				}
			}

			void SetSelect(int select)
			{
				m_IsSelect = select;
			}
		/*	void PreUpdate();
			void Update();
			void PostUpdate();*/

		private:
			//class RawMesh* m_MeshResource;
			StaticMeshRendererComponent* m_MeshComponent;
			RigidBodyComponent* m_RigidBodyComponent;
			BoxComponent* m_BoxComponent;
			//world::AnimationComponent* m_AnimationComponent;
			/*float3 DiffuseColor;*/
			int Frozon = 0;
			int m_IsSelect;
			Scene* m_Scene;
			float3 m_Position;
		private:
			
		};
	}


}


