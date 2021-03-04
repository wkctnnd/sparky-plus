#pragma once
#include "gameinstance.h"
#include <vector>
#include <List>
#include "maths/vec3.h"
#include "utils/random.h"
#include "lobby5.h"
#include "utils/log.h"

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
 
		class MyGameInstance5 :public GameInstance
		{
		public:
			void Update();
			void PostRender();
			void Init();

		private:
			//std::vector<world::Actor*> m_Astronauts;
			//world::Actor* m_Lobby;

			//world::Actor* m_Player;

			asset::RawMesh*  m_AssetResource;
			asset::Material* m_MaterialResource;
			world::CameraComponent* m_RightCamera;

			world::Actor *m_CameraRoot;
			asset::AssetManager* m_AssetManager;
		private:

			Lobby4 *m_Lobby;
			Logger* m_Log;
		};
	}
}

