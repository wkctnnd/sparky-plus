#pragma once
#include <vector>
namespace sparky
{
	namespace render
	{
		class Renderer;
	}
}

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

			render::SceneRenderer* GetRenderer() { return m_SceneRenderer; }
			Actor* GetRoot() { return m_RootActor; }
			static Scene* GetCurrentScene() { return m_CurrentScene; };
		private:

			static Scene* m_CurrentScene;
			std::vector<Actor*> m_AllActors;
			
			Actor* m_RootActor;
			render::SceneRenderer* m_SceneRenderer;
		};
	}
}