#pragma once
#include <vector>
namespace sparky
{
	namespace world
	{
		class Actor;
		class Scene;
	}
	namespace game
	{
		class GameInstance
		{
		public:
			virtual void Init() = 0;
			virtual void Update() = 0;
			virtual void PostRender() = 0;
			world::Scene* GetScene() {
				return m_Scene;
			}
		protected:

			world::Scene* m_Scene;
		};
	}
}
