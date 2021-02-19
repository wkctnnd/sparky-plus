#include "Lobby4.h"
#include "Asset/rawmesh.h"
using namespace sparky::asset;
namespace sparky
{
	namespace game
	{

		float Lobby4::m_LobbyX;
		float Lobby4::m_LobbyY;
		float Lobby4::m_LobbyZ;
		Lobby4::Lobby4(class Scene* scene, asset::RawMesh* lobbymesh, RawMesh* cubemesh, RawMesh* spheremesh, RawMesh* centrummesh)
		{
			//µØÃæ
			m_Wall1 = new Actor();
			m_RandomEngine.Seed(Engine::GlobalTimer.GetTime());


			StaticMeshRendererComponent* meshcomponent = m_Wall1->AddComponent<StaticMeshRendererComponent>();
			meshcomponent->AddStaticMesh(lobbymesh);

			Material* material = new Material();
			material->SetDiffuseColor(0.455, 0.305, 0.305, 1);
			meshcomponent->AddMaterial(material);
			m_Wall1->GetTransform()->SetLocalScale(float3(m_LobbyX, m_LobbyY, m_LobbyZ));
			Attach(m_Wall1);

		


			scene->AddActor(this);


			 
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