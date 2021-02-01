#pragma once
#include "gameinstance.h"
#include <vector>
#include <List>
#include "maths/vec3.h"
#include "utils/random.h"
#include "lobby3.h"
 
using namespace std;
using namespace sparky::maths;
namespace sparky
{
	namespace world
	{
		class Scene;
		class CameraComponent;
	}
	namespace asset
	{
		class RawMesh;
		class AssetManager;
	}
	namespace game
	{
 
		class MyGameInstance3 :public GameInstance
		{
		public:
			void Update();

			void Init();

		private:
			//std::vector<world::Actor*> m_Astronauts;
			//world::Actor* m_Lobby;

			//world::Actor* m_Player;

			asset::RawMesh*  m_BallResource;
			asset::RawMesh*	 m_CubeResource;
			/*asset::RawMesh*  m_LobbyResource;*/
			asset::RawMesh*  m_CentrumResource;
 
			asset::RawMesh* m_LobbyResource;
 

		 
			asset::AssetManager* m_AssetManager;
			world::CameraComponent* m_CameraComponent;

		private:

			Lobby3 *m_Lobby;
		};
	}
}

