#pragma once
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
#include "Asset/rawmesh.h"
#include "utils/random.h"
using namespace sparky::world;
using namespace sparky::asset;
namespace sparky
{
	namespace game
	{
		class Lobby3 :public Actor
		{
		public:
			Lobby3(class Scene* scene,  asset::RawMesh* lobbymesh, RawMesh* cubemesh, RawMesh* spheremesh, RawMesh* centrummesh)
			{
				//µØÃæ
				m_Wall1 = new Actor();

				float x, y, z;
				m_RandomEngine.GenNormalRandomNumber(&x, 1, 4, 0.09);
				m_RandomEngine.GenNormalRandomNumber(&y, 1, 3, 0.09);
				m_RandomEngine.GenNormalRandomNumber(&z, 1, 0.8, 0.01);
				StaticMeshRendererComponent* meshcomponent = m_Wall1->AddComponent<StaticMeshRendererComponent>();
				meshcomponent->AddStaticMesh(lobbymesh);
				Attach(m_Wall1);
	
				int objnum;
				m_RandomEngine.GenUniformRandomNumber(&objnum, 1, 8, 10);

				m_LeatherBox = 
				for (int i=0;i<objnum;i++)
				{
					Actor* obj = new Actor();

				}

				scene->AddActor(this);
			}


			void AddBoxColliderActor();
			/*void PreUpdate() {};
			void Update() {};
			void PostUpdate() {};*/


		private:
			//class RawMesh* m_MeshResource;
		 
		
			Actor* m_Wall1;
			Actor* m_LeatherBox;
			std::vector<Actor*> m_Objects;
			Random m_RandomEngine;
		private:
			RawMesh GenerateRawMesh(float length,float3 offset);
		
		};
	}


}


