#pragma once
#include "gameinstance.h"
#include <vector>
#include <List>
#include "maths/vec3.h"
#include "utils/random.h"
#include "box.h"
#include "button.h"
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
	}
	namespace game
	{
		class Robot;
		class Player;
		class Lobby;
		class  Lobby2;
		class Door;
		class MyGameInstance2 :public GameInstance
		{
		public:
			void Update();

			void Init();

		private:
			//std::vector<world::Actor*> m_Astronauts;
			//world::Actor* m_Lobby;

			//world::Actor* m_Player;

			asset::RawMesh*  m_BodyResource;
			asset::RawMesh*	 m_LeftArmResource;
			asset::RawMesh*  m_RightArmResource;

			asset::RawMesh*  m_LeftDoorResource;
			asset::RawMesh*  m_RightDoorResouce;

			asset::RawMesh* m_TreeResource;
			asset::RawMesh* m_FloorResource;
			asset::RawMesh* m_WallResource;

		 
			Player* m_Player;
			Lobby* m_Lobby;
			Lobby2* m_Lobby2;
			Button* m_Button;
			Box* m_Box;
			Door* m_LeftDoor;
			Door* m_RightDoor;
			world::CameraComponent* m_CameraComponent;

		private:

			 
		};
	}
}

