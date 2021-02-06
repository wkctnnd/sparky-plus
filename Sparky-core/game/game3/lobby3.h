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
using namespace sparky::maths;
namespace sparky
{
	namespace game
	{

		struct PathPoint 
		{
			float3 position;
			float3 direction;
			float angle;
			float globalangle;
		};

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
				m_LobbyX = x;
				m_LobbyY = y;
				m_LobbyZ = z;
				StaticMeshRendererComponent* meshcomponent = m_Wall1->AddComponent<StaticMeshRendererComponent>();
				meshcomponent->AddStaticMesh(lobbymesh);
				m_Wall1->GetTransform()->SetLocalScale(float3(x, y, z));
				Attach(m_Wall1);
				
				quad* q = new quad(float3(0, 0, 0), float3(x, y, z));
				m_Map.AddWall(*q);

				//任选一个位置的
				m_LeatherBox = new Actor();
				int leatherpos;
				m_RandomEngine.GenUniformRandomNumber
				(&leatherpos, 1, 4, 1);
				float3 position;
				if (leatherpos==1)
				{
					position = float3(100, 0, 100);
				}
				else if (leatherpos==2)
				{
					position = (float3(100, 0, -100));
				}
				else if (leatherpos==3)
				{
					position = (float3(-100, 0, 100));
				}
				else
				{
					position = (float3(-100, 0, -100));
				}

		
				m_LeatherBox->GetTransform()->SetLocalPosition(position);
				m_LeatherBox->GetTransform()->SetLocalScale(float3(500, 800, 1000));

				Attach(m_LeatherBox);

				q = new quad(position, float3(500, 800, 1000));
				m_Map.AddWall(*q);

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
						
					
						m_RandomEngine.GenUniformRandomNumber(&posx, 1, x, 0.0f);
						m_RandomEngine.GenUniformRandomNumber(&posy, 1, y, 0.0f);
						m_RandomEngine.GenUniformRandomNumber(&posz, 1, z, 0.0f);

					

						
					}
					quad* q = new quad(float3(posx, posy, posz), float3(1, 1, 1));
					res = m_Map.AddBox(*q);
					obj->GetTransform()->SetLocalPosition(float3(posx, posy, posz));

					Attach(obj);
				}

				scene->AddActor(this);
			}


			void AddBoxColliderActor();
			/*void PreUpdate() {};
			void Update() {};
			void PostUpdate() {};*/

			void GenCameraPath();
			PathPoint GetPathPoint(int i);
		private:
			//class RawMesh* m_MeshResource;
		 
		
			Actor* m_Wall1;
			Actor* m_LeatherBox;
			std::vector<Actor*> m_Objects;
			Random m_RandomEngine;
		private:
			RawMesh GenerateRawMesh(float length,float3 offset);
			Map m_Map;

			PathPoint path[15];
			float m_LobbyX, m_LobbyY, m_LobbyZ;
		};
	}


}


