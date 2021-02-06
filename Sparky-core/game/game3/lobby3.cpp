#include "Lobby3.h"
#include "Asset/rawmesh.h"
using namespace sparky::asset;
namespace sparky
{
	namespace game
	{
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
			float dis[14];
			float angle[15];
			float x, y, z;
			m_RandomEngine.GenUniformRandomNumber(&path[0].position.x, 1, m_LobbyX, 0.0f);
			m_RandomEngine.GenUniformRandomNumber(&path[0].position.y, 1, m_LobbyY, 0.0f);
			m_RandomEngine.GenUniformRandomNumber(&path[0].position.z, 1, m_LobbyZ, 0.0f);
			
 
			m_RandomEngine.GenNormalRandomNumber(dis, 14, 10, 6);
			m_RandomEngine.GenNormalRandomNumber(angle, 15, 0, 0.1);

			path[0].globalangle = angle[0];
			float4 initdir(1, 0, 0, 0);
			for (int i=1;i<15;i++)
			{
				float moveangle;
				
				m_RandomEngine.GenNormalRandomNumber(&moveangle, 1, 3.1415926 / 10, 0.1);

				Quaternion r = Quaternion::FromEulerXYZ(0, moveangle, 0);
				float4 newdir = r.GetMatrix()*initdir;
				float3 ndir(newdir.x, newdir.y, newdir.z);
				r = Quaternion::FromEulerXYZ(0, path[i].angle, 0);
				//float4 newcameradir = r.GetMatrix()*newdir;

				path[i].position = path[i - 1].position + ndir * dis[i];
				path[i].globalangle = path[i - 1].globalangle+ moveangle;


				initdir = newdir;
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