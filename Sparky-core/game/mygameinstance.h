#pragma once
#include "gameinstance.h"
#include <vector>
#include <List>

using namespace std;
namespace sparky
{
	namespace world
	{
		class Scene;
	}
	namespace asset
	{
		class RawMesh;
	}
	namespace game
	{
		class Robot;
		class Player;
		class Lobby;
		class MyGameInstance :public GameInstance
		{
		public:
			void Update();

			void Init();

		private:
			//std::vector<world::Actor*> m_Astronauts;
			//world::Actor* m_Lobby;
			world::Scene* m_Scene;
			//world::Actor* m_Player;

			asset::RawMesh*  m_Astronautmeshresource;
			asset::RawMesh*	 m_Lobbyresource;

			list<Robot*> m_Robots;
			Player* m_Player;
			Lobby* m_Lobby;

		};
	}
}
 
