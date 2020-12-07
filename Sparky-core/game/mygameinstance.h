#pragma once
#include "gameinstance.h"
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
		class MyGameInstance :public GameInstance
		{
		public:
			void Update();

			void Init();

		private:
			//std::vector<world::Actor*> m_Astronauts;
			world::Actor* m_Lobby;
			world::Scene* m_Scene;
			world::Actor* m_Player;

			asset::RawMesh*  m_Astronautmeshresource;
			asset::RawMesh*	 m_Lobbyresource;

			vector<class Robot*> m_Robots;
			class Player* m_Player;
			class Lobby* m_Lobby;

		};
	}
}
 
