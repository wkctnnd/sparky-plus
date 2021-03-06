#pragma once
#include "world/actor.h"
#include "world/scene.h"
#include "world/component/staticmeshrenderercomponent.h"
#include "world/component/rigidbodycomponent.h"
#include "Asset/rawmesh.h"
#include "utils/random.h"
#include "asset/material.h"
 
#include "engine.h"
using namespace sparky::world;
using namespace sparky::asset;
using namespace sparky::maths;
namespace sparky
{
	namespace game
	{

 

		class Lobby4 :public Actor
		{
		public:
			Lobby4(class Scene* scene, asset::RawMesh* lobbymesh, asset::Material* mat);
		 
		private:
			//class RawMesh* m_MeshResource;
		 
 
			Actor* m_HouseBox;
			std::vector<Actor*> m_Objects;
			Random m_RandomEngine;
		private:
		
	 
			static float m_LobbyX, m_LobbyY, m_LobbyZ;
		};
	}


}


