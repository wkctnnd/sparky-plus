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
			Lobby(class Scene* scene, class asset::RawMesh* FloorMeshResourc, class asset::RawMesh* Wall0Resourc, class asset::RawMesh*Wall1MeshResourc, class asset::RawMesh* Wall2MeshResourc, class asset::RawMesh* TreeMeshResource, class asset::RawMesh* BoxMeshResource, class asset::RawMesh* ButtonMeshResource, class asset::Material* boxmaterial, class asset::Material* floormaterial)
			{
				//µØÃæ
				m_Floor = new Actor("Floor");
				StaticMeshRendererComponent* floormeshcomponent = m_Floor->AddComponent<StaticMeshRendererComponent>();
				floormeshcomponent->AddStaticMesh(FloorMeshResourc);
				floormeshcomponent->AddMaterial(floormaterial);
				//RigidBodyComponent* leftarmbodycomponent = m_Floor->AddComponent<RigidBodyComponent>();
				//leftarmbodycomponent->GenerateShape(FloorMeshResourc, phyx::ShapeType::AABB_Shape);
				Attach(m_Floor);
				//Ç½±Ú
				m_Wall0 = new Actor("Wall0");
				StaticMeshRendererComponent* rightarmmeshcomponent = m_Wall0->AddComponent<StaticMeshRendererComponent>();
				rightarmmeshcomponent->AddStaticMesh(Wall0Resourc);
				RigidBodyComponent* rightarmbodycomponent = m_Wall0->AddComponent<RigidBodyComponent>();
				rightarmbodycomponent->GenerateShape(Wall0Resourc, phyx::ShapeType::AABB_Shape);
				Attach(m_Wall0);

				m_Wall1 = new Actor("Wall1");
				rightarmmeshcomponent = m_Wall1->AddComponent<StaticMeshRendererComponent>();
				rightarmmeshcomponent->AddStaticMesh(Wall1MeshResourc);
				rightarmbodycomponent = m_Wall1->AddComponent<RigidBodyComponent>();
				rightarmbodycomponent->GenerateShape(Wall1MeshResourc, phyx::ShapeType::AABB_Shape);
				Attach(m_Wall1);


				m_Wall2 = new Actor("Wall2");
				rightarmmeshcomponent = m_Wall2->AddComponent<StaticMeshRendererComponent>();
				rightarmmeshcomponent->AddStaticMesh(Wall2MeshResourc);
				rightarmbodycomponent = m_Wall2->AddComponent<RigidBodyComponent>();
				rightarmbodycomponent->GenerateShape(Wall2MeshResourc, phyx::ShapeType::AABB_Shape);
				Attach(m_Wall2);
				//Ê÷Ä¾
				m_Tree = new Actor("Tree");
				StaticMeshRendererComponent* treemmeshcomponent = m_Tree->AddComponent<StaticMeshRendererComponent>();
				treemmeshcomponent->AddStaticMesh(TreeMeshResource);
				Attach(m_Tree);
				////ÓÒ±ßÃÅ
				//m_RightDoor = new Actor("RightDoor");
				//StaticMeshRendererComponent* rightdoormeshcomponent = m_RightDoor->AddComponent<StaticMeshRendererComponent>();
				//rightdoormeshcomponent->AddStaticMesh(RightDoorMeshResourc);
				//RigidBodyComponent* rightdoorrigidbodycomponent = m_Wall->AddComponent<RigidBodyComponent>();
				//rightdoorrigidbodycomponent->GenerateShape(RightDoorMeshResourc, phyx::ShapeType::AABB_Shape);
				//Attach(m_RightDoor);
				////×ó±ßÃÅ
				//m_LeftDoor = new Actor("LeftDoor");
				//StaticMeshRendererComponent* leftdoormeshcomponent = m_LeftDoor->AddComponent<StaticMeshRendererComponent>();
				//leftdoormeshcomponent->AddStaticMesh(LeftDoorMeshResourc);
				//RigidBodyComponent* leftdoorrigidbodycomponent = m_LeftDoor->AddComponent<RigidBodyComponent>();
				//leftdoorrigidbodycomponent->GenerateShape(LeftDoorMeshResourc, phyx::ShapeType::AABB_Shape);
				//Attach(m_LeftDoor);

				//Ïä×Ó
			/*	m_Box = new Actor("Box");
				StaticMeshRendererComponent* boxmeshcomponent = m_Box->AddComponent<StaticMeshRendererComponent>();
				boxmeshcomponent->AddStaticMesh(BoxMeshResource);
				boxmeshcomponent->AddMaterial(boxmaterial);
				RigidBodyComponent*boxrigidbodycomponent = m_Box->AddComponent<RigidBodyComponent>();
				boxrigidbodycomponent->GenerateShape(BoxMeshResource, phyx::ShapeType::AABB_Shape);
				Attach(m_Box);*/
				////Ñ¹Á¦°å
				//m_Button = new Actor();
				//StaticMeshRendererComponent* buttonmeshcomponent = m_Button->AddComponent<StaticMeshRendererComponent>();
				//buttonmeshcomponent->AddStaticMesh(ButtonMeshResource);
				//RigidBodyComponent*buttonrigidbodycomponent = m_Button->AddComponent<RigidBodyComponent>();
				//buttonrigidbodycomponent->GenerateShape(BoxMeshResource, phyx::ShapeType::AABB_Shape);
				//Attach(m_Button);

				scene->AddActor(this);
			}


			void AddBoxColliderActor();
			/*void PreUpdate() {};
			void Update() {};
			void PostUpdate() {};*/


		private:
			//class RawMesh* m_MeshResource;
		 
			
			Actor* m_Floor;
			Actor* m_Wall0;
			Actor* m_Tree;
			Actor* m_Box;
			Actor* m_Button;
			Actor* m_Wall1;
			Actor* m_Wall2;
		private:
			RawMesh GenerateRawMesh(float length,float3 offset);
 
		};
	}


}


