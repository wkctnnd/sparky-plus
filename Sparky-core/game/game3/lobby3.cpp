#include "Lobby3.h"
#include "Asset/rawmesh.h"
using namespace sparky::asset;
namespace sparky
{
	namespace game
	{

		float Lobby3::m_LobbyX;
		float Lobby3::m_LobbyY;
		float Lobby3::m_LobbyZ;
		Lobby3::Lobby3(class Scene* scene, asset::RawMesh* lobbymesh, RawMesh* cubemesh, RawMesh* spheremesh, RawMesh* centrummesh)
		{
			//地面
			m_Wall1 = new Actor();
			m_RandomEngine.Seed(Engine::GlobalTimer.GetTime());
			float x, y, z;
			m_RandomEngine.GenNormalRandomNumber(&x, 1, 4, 0.09);
			m_RandomEngine.GenNormalRandomNumber(&y, 1, 0.8, 0.01);
			m_RandomEngine.GenNormalRandomNumber(&z, 1, 3, 0.09);
			m_LobbyX = x * 100;
			m_LobbyY = y * 100;
			m_LobbyZ = z * 100;
			StaticMeshRendererComponent* meshcomponent = m_Wall1->AddComponent<StaticMeshRendererComponent>();
			meshcomponent->AddStaticMesh(lobbymesh);

			Material* material = new Material();
			material->SetDiffuseColor(0.455, 0.305, 0.305, 1);
			meshcomponent->AddMaterial(material);
			m_Wall1->GetTransform()->SetLocalScale(float3(m_LobbyX, m_LobbyY, m_LobbyZ));
			Attach(m_Wall1);

			quad* q = new quad(float2(0, 0), float2(m_LobbyX, m_LobbyZ));
			m_Map.AddWall(*q);

			//任选一个位置的
			m_LeatherBox = new Actor();
		
			int leatherpos;
			m_RandomEngine.GenUniformRandomNumber(&leatherpos, 1, 5, 1);
			float3 position;
			if (leatherpos == 1)
			{
				position = float3(m_LobbyX / 2.0-25, 0, m_LobbyX / 2.0-50);
			}
			else if (leatherpos == 2)
			{
				position = (float3(m_LobbyX / 2.0-25, 0, -m_LobbyX / 2.0+50));
			}
			else if (leatherpos == 3)
			{
				position = (float3(-m_LobbyX / 2.0 + 25, 0, m_LobbyX / 2.0 - 50));
			}
			else
			{
				position = (float3(-m_LobbyX / 2.0+25, 0, -m_LobbyX / 2.0+50));
			}


			m_LeatherBox->GetTransform()->SetLocalPosition(position);
			m_LeatherBox->GetTransform()->SetLocalScale(float3(50, 80, 100));
			meshcomponent = m_LeatherBox->AddComponent<StaticMeshRendererComponent>();
			meshcomponent->AddStaticMesh(cubemesh);
			Material* leathermaterial = new Material();
			leathermaterial->SetDiffuseColor(0.7, 0.7, 0, 1);
			meshcomponent->AddMaterial(leathermaterial);
			//Attach(m_LeatherBox);
			scene->AddActor(m_LeatherBox);
			q = new quad(float2(position.x, position.z), float2(50, 100));
			m_Map.AddBox(*q);

			//随机8-10个的物体，随机选择椎体

			int objnum;
			m_RandomEngine.GenUniformRandomNumber(&objnum, 1, 10, 8);

			for (int i = 0; i < objnum; i++)
			{
				Actor* obj = new Actor();

				int type;

				m_RandomEngine.GenUniformRandomNumber(&type, 1, 3, 0);
				float objy = 0;
				switch (type)
				{
				case 0:
				{
					StaticMeshRendererComponent* meshcomponent = obj->AddComponent<StaticMeshRendererComponent>();
					meshcomponent->AddStaticMesh(cubemesh);
					break;
				}
				case 1:
				{
					StaticMeshRendererComponent* meshcomponent = obj->AddComponent<StaticMeshRendererComponent>();
					meshcomponent->AddStaticMesh(spheremesh);
					objy = 20;
					break;
				}
				case 2:
				{
					StaticMeshRendererComponent* meshcomponent = obj->AddComponent<StaticMeshRendererComponent>();
					meshcomponent->AddStaticMesh(centrummesh);
					break;
				}
				default:
					break;
				}

				Material* objmaterial = new Material();
				objmaterial->SetDiffuseColor(0.443, 0.3529, 0.388, 1);
				meshcomponent->AddMaterial(objmaterial);



				bool res = false;
				float posx, posy, posz;
				while (!res)
				{


					m_RandomEngine.GenUniformRandomNumber(&posx, 1, m_LobbyX / 2.0f, -m_LobbyX / 2.0f);
					//m_RandomEngine.GenUniformRandomNumber(&posy, 1, y, 0.0f);
					m_RandomEngine.GenUniformRandomNumber(&posz, 1, m_LobbyZ / 2.0f, -m_LobbyZ / 2.0f);

					quad* q = new quad(float2(posx, posz), float2(20, 20));
					res = m_Map.AddBox(*q);


				}

				obj->GetTransform()->SetLocalPosition(float3(posx, objy, posz));
				obj->GetTransform()->SetLocalScale(float3(20.0f, 20.f, 20.f));
				scene->AddActor(obj);
			}

			scene->AddActor(this);


			GenCameraPath();
		}



		RawMesh Lobby3::GenerateRawMesh(float length, float3 offset)
		{
		 
			RawMesh mesh;
 
			mesh.m_Position.push_back(float3(0, 0, 0) + offset);
			mesh.m_Position.push_back(float3(length, 0, 0) + offset);
			mesh.m_Position.push_back(float3(length, length, 0) + offset);
			mesh.m_Position.push_back(float3(0, length, 0) + offset);

			mesh.m_Position.push_back(float3(0, 0, length) + offset);
			mesh.m_Position.push_back(float3(length, 0, length) + offset);
			mesh.m_Position.push_back(float3(length, length, length) + offset);
			mesh.m_Position.push_back(float3(0, length, length) + offset);


			mesh.m_Faces.push_back(0);
			mesh.m_Faces.push_back(1);
			mesh.m_Faces.push_back(2);
			mesh.m_Faces.push_back(0);
			mesh.m_Faces.push_back(2);
			mesh.m_Faces.push_back(3);


			mesh.m_Faces.push_back(6);
			mesh.m_Faces.push_back(5);
			mesh.m_Faces.push_back(4);
			mesh.m_Faces.push_back(4);
			mesh.m_Faces.push_back(7);
			mesh.m_Faces.push_back(6);



			mesh.m_Faces.push_back(1);
			mesh.m_Faces.push_back(5);
			mesh.m_Faces.push_back(6);
			mesh.m_Faces.push_back(1);
			mesh.m_Faces.push_back(6);
			mesh.m_Faces.push_back(2);

			mesh.m_Faces.push_back(0);
			mesh.m_Faces.push_back(7);
			mesh.m_Faces.push_back(4);
			mesh.m_Faces.push_back(0);
			mesh.m_Faces.push_back(3);
			mesh.m_Faces.push_back(7);


			mesh.m_Faces.push_back(3);
			mesh.m_Faces.push_back(2);
			mesh.m_Faces.push_back(6);
			mesh.m_Faces.push_back(3);
			mesh.m_Faces.push_back(6);
			mesh.m_Faces.push_back(7);

			//mesh.m_Faces.push_back(6);
			mesh.m_Faces.push_back(0);
			mesh.m_Faces.push_back(5);
			mesh.m_Faces.push_back(1);
			mesh.m_Faces.push_back(0);
			mesh.m_Faces.push_back(4);
			mesh.m_Faces.push_back(5);

			return mesh;

		}


		void Lobby3::GenCameraPath()
		{
			float dis;
			float angle;
			float x, y, z;

			bool res = true;
			while (res)
			{
				m_RandomEngine.GenUniformRandomNumber(&path[0].position.x, 1, m_LobbyX / 2.0f, -m_LobbyX / 2.0f);
				m_RandomEngine.GenUniformRandomNumber(&path[0].position.z, 1, m_LobbyZ / 2.0f, -m_LobbyZ / 2.0f);
				res = !m_Map.CheckPoint(float2(path[0].position.x, path[0].position.z));
			}
	
			path[0].position.y = 10;
			
			
 
			m_RandomEngine.GenNormalRandomNumber(&angle, 1, 0.0f, 0.1f);

			path[0].globalangle = 0;
			float4 initdir(1, 0, 0, 0);
			path[0].cameraangle = angle;
			for (int i=1;i<15;i++)
			{
				float moveangle;
				
				
				bool res = true;
				float3 ndir;
				while (res)
				{
					m_RandomEngine.GenNormalRandomNumber(&dis, 1, 10.0f, 6.0f);
					m_RandomEngine.GenNormalRandomNumber(&angle, 1, 0.0f, 0.1f);

					m_RandomEngine.GenNormalRandomNumber(&moveangle, 1, 3.1415926 / 10, 0.1);
					path[i].globalangle = path[i - 1].globalangle + moveangle;


					Quaternion r = Quaternion::FromEulerXYZ(0, path[i].globalangle, 0);
					float4 newdir = r.GetMatrix()*initdir;
					//float3 ndir(newdir.x, newdir.y, newdir.z);
					ndir.x = newdir.x;
					ndir.y = newdir.y;
					ndir.z = newdir.z;

					r = Quaternion::FromEulerXYZ(0, path[i].globalangle, 0);
					//float4 newcameradir = r.GetMatrix()*newdir;
					float4 newcameradir = r.GetMatrix()*initdir;


					float3 pos = path[i - 1].position + ndir * dis;
					res = !m_Map.CheckPoint(float2(pos.x, pos.z));
					
				}
				path[i].position = path[i - 1].position + ndir * dis;
				
				path[i].cameraangle = path[i].globalangle + angle;

				/*initdir = newdir;*/
			}
		}

		PathPoint Lobby3::GetPathPoint(int i)
		{
			return path[i];
		}

		void Lobby3::AddBoxColliderActor()
		{

			{
				RawMesh mesh0 = GenerateRawMesh(5, float3(8, 0, 4.3));
				Actor *actor = new Actor();
				StaticMeshRendererComponent* sc = actor->AddComponent<StaticMeshRendererComponent>();
				sc->AddStaticMesh(&mesh0);		
				RigidBodyComponent* rc = actor->AddComponent<RigidBodyComponent>();
				rc->GenerateShape(&mesh0, phyx::ShapeType::AABB_Shape);
				Attach(actor);
				

				mesh0 = GenerateRawMesh(5, float3(-10.7, 0, 7.3));
				actor = new Actor();
				sc = actor->AddComponent<StaticMeshRendererComponent>();
				sc->AddStaticMesh(&mesh0);
				rc = actor->AddComponent<RigidBodyComponent>();
				rc->GenerateShape(&mesh0, phyx::ShapeType::AABB_Shape);
				Attach(actor);



				mesh0 = GenerateRawMesh(5, float3(-10.4, 0, -3.3));
				actor = new Actor();
				sc = actor->AddComponent<StaticMeshRendererComponent>();
				sc->AddStaticMesh(&mesh0);
				rc = actor->AddComponent<RigidBodyComponent>();
				rc->GenerateShape(&mesh0, phyx::ShapeType::AABB_Shape);
				Attach(actor);
			}
		}
	}
}