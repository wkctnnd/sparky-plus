#pragma once
#include "gameinstance.h"
#include <vector>
#include <List>
#include "maths/vec3.h"
#include "utils/random.h"
using namespace std;
using namespace sparky::maths;
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
			
			//world::Actor* m_Player;

			asset::RawMesh*  m_Astronautmeshresource;
			asset::RawMesh*	 m_Lobbyresource;

			list<Robot*> m_Robots;
			Player* m_Player;
			Lobby* m_Lobby;

			Random m_RandomEngine;

		private:
			void GenerateRobot();
			void SetColor(Robot* r, float3 color);
			float3 GetRandomColor()
			{
				float num[3];
				m_RandomEngine.GenerateRandomNumber(num, 3, 1, 0);
				float3 temp(num[0], num[1], num[2]);

				return temp.NormalizeSelf();
			}

			float3 GetRandomPosition()
			{
				float num[3];
				m_RandomEngine.GenerateRandomNumber(num, 3, 20, 0);
				float3 temp(num[0]-5, 0, num[2]-5);

				return temp;
			}
		};
	}
}
 
