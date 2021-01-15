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
		class Lobby2 :public Actor
		{
		public:
			Lobby2(class Scene* scene, class asset::RawMesh* boxmesh, class asset::RawMesh* buttonmesh, class asset::RawMesh*wall0mesh, class asset::RawMesh* leftdoormesh, class asset::RawMesh* rightdoormesh, class asset::RawMesh* blockmesh, class asset::RawMesh* planemesh, class asset::RawMesh* wall2mesh, class asset::RawMesh* treemesh, class asset::Material* boxmaterial)
			{
				//µØÃæ
				m_Box = new Actor();
				StaticMeshRendererComponent* meshcomponent = m_Box->AddComponent<StaticMeshRendererComponent>();
				meshcomponent->AddStaticMesh(boxmesh);
				Attach(m_Box);
	
				m_Button = new Actor();
				meshcomponent = m_Button->AddComponent<StaticMeshRendererComponent>();
				meshcomponent->AddStaticMesh(buttonmesh);
				Attach(m_Button);

				m_Wall1 = new Actor();
				meshcomponent = m_Wall1->AddComponent<StaticMeshRendererComponent>();
				meshcomponent->AddStaticMesh(wall0mesh);
				Attach(m_Wall1);


				m_LeftDoor = new Actor();
				meshcomponent = m_LeftDoor->AddComponent<StaticMeshRendererComponent>();
				meshcomponent->AddStaticMesh(leftdoormesh);
				Attach(m_LeftDoor);

				m_RightDoor = new Actor();
				meshcomponent = m_RightDoor->AddComponent<StaticMeshRendererComponent>();
				meshcomponent->AddStaticMesh(rightdoormesh);
				Attach(m_RightDoor);

				m_Block = new Actor();
				meshcomponent = m_Block->AddComponent<StaticMeshRendererComponent>();
				meshcomponent->AddStaticMesh(blockmesh);
				Attach(m_Block);

				m_Plane = new Actor();
				meshcomponent = m_Plane->AddComponent<StaticMeshRendererComponent>();
				meshcomponent->AddStaticMesh(planemesh);
				Attach(m_Plane);

				m_Tree = new Actor();
				meshcomponent = m_Tree->AddComponent<StaticMeshRendererComponent>();
				meshcomponent->AddStaticMesh(treemesh);
				Attach(m_Tree);

				m_Wall2 = new Actor();
				meshcomponent = m_Tree->AddComponent<StaticMeshRendererComponent>();
				meshcomponent->AddStaticMesh(wall2mesh);
				Attach(m_Wall2);

				scene->AddActor(this);
			}


			void AddBoxColliderActor();
			/*void PreUpdate() {};
			void Update() {};
			void PostUpdate() {};*/


		private:
			//class RawMesh* m_MeshResource;
		 
			
			Actor* m_Box;
			Actor* m_Button;
			Actor* m_Wall1;
			Actor* m_LeftDoor;
			Actor* m_RightDoor;
			Actor* m_Block;
			Actor* m_Plane;
			Actor* m_Tree;
			 
	 
		
			Actor* m_Wall2;
		private:
			RawMesh GenerateRawMesh(float length,float3 offset);
 
		};
	}


}


