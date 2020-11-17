#pragma once
#include <vector>


namespace sparky
{
	namespace world
	{
		class TransformComponent;
		class Actor;
		class Scene
		{
		public:
			void Initialize();
			void AddActor(Actor* atr);
			void Update(float t);

			Actor* GetRoot() { return m_RootActor; }
			static Scene* GetCurrentScene() { return m_CurrentScene; };
		private:

			static Scene* m_CurrentScene;
			std::vector<Actor*> m_AllActors;
			
			Actor* m_RootActor;
		};
	}
}