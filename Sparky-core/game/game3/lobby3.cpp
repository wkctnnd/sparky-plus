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