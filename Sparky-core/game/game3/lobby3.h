#pragma once
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
#include "Asset/rawmesh.h"
#include "utils/random.h"
#include "map.h"
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
				//地面
				m_Wall1 = new Actor();

				float x, y, z;
				m_RandomEngine.GenNormalRandomNumber(&x, 1, 4, 0.09);
				m_RandomEngine.GenNormalRandomNumber(&y, 1, 3, 0.09);
				m_RandomEngine.GenNormalRandomNumber(&z, 1, 0.8, 0.01);
				StaticMeshRendererComponent* meshcomponent = m_Wall1->AddComponent<StaticMeshRendererComponent>();
				meshcomponent->AddStaticMesh(lobbymesh);
				m_Wall1->GetTransform()->SetLocalScale(float3(x, y, z));
				Attach(m_Wall1);
				
				quad q(float3(0, 0, 0), float3(x, y, z));
				m_Map.AddWall(q);

				//任选一个位置的
				m_LeatherBox = new Actor();
				int leatherpos;
				m_RandomEngine.GenUniformRandomNumber(&leatherpos, 1, 4, 1);
				if (leatherpos==1)
				{
					m_LeatherBox->GetTransform()->SetLocalPosition(float3(100, 0, 100));
				}
				else if (leatherpos==2)
				{
					m_LeatherBox->GetTransform()->SetLocalPosition(float3(100, 0, -100));
				}
				else if (leatherpos==3)
				{
					m_LeatherBox->GetTransform()->SetLocalPosition(float3(-100, 0, 100));
				}
				else
				{
					m_LeatherBox->GetTransform()->SetLocalPosition(float3(-100, 0, -100));
				}

				m_LeatherBox->GetTransform()->SetLocalScale(float3(500, 800, 1000));

				Attach(m_LeatherBox);



				//随机8-10个的物体，随机选择椎体

				int objnum;
				m_RandomEngine.GenUniformRandomNumber(&objnum, 1, 8, 10);

				for (int i=0;i<objnum;i++)
				{
					Actor* obj = new Actor();

					int type;

					m_RandomEngine.GenUniformRandomNumber(&type, 1, 2, 0);

					switch (type)
					{
					case 1:
					{
						StaticMeshRendererComponent* meshcomponent = m_Wall1->AddComponent<StaticMeshRendererComponent>();
						meshcomponent->AddStaticMesh(cubemesh);
						break;
					}
					case 2:
					{
						StaticMeshRendererComponent* meshcomponent = m_Wall1->AddComponent<StaticMeshRendererComponent>();
						meshcomponent->AddStaticMesh(spheremesh);
						break;
					}
					case 3:
					{
						StaticMeshRendererComponent* meshcomponent = m_Wall1->AddComponent<StaticMeshRendererComponent>();
						meshcomponent->AddStaticMesh(centrummesh);
						break;
					}
					default:
						break;
					}

					


					
					
					bool res = false;
					float posx, posy, posz;
					while (!res)
					{
						quad q;

					
						m_RandomEngine.GenUniformRandomNumber(&posx, 1, x, 0.0f);
						m_RandomEngine.GenUniformRandomNumber(&posy, 1, y, 0.0f);
						m_RandomEngine.GenUniformRandomNumber(&posz, 1, z, 0.0f);

					

						res = m_Map.AddBox(q);
					}

					obj->GetTransform()->SetLocalPosition(float3(posx, posy, posz));

					Attach(obj);
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
			Map m_Map;
		};
	}


}


