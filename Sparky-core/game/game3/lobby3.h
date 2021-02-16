#pragma once
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
#include "Asset/rawmesh.h"
#include "utils/random.h"
#include "map.h"
#include "engine.h"
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
			float cameraangle;
			float globalangle;
		};

		class Lobby3 :public Actor
		{
		public:
			Lobby3(class Scene* scene, asset::RawMesh* lobbymesh, RawMesh* cubemesh, RawMesh* spheremesh, RawMesh* centrummesh);


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
			static float m_LobbyX, m_LobbyY, m_LobbyZ;
		};
	}


}


